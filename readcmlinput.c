/*******************************************************************************
* Program: Store File Contents Into A Dynamically Allocated Array Of Lines
* Description: Reads a file line by line and stores each line in a dynamically
* allocated array of dynamically allocated strings. Both the array of lines and
* each individual line grow as needed, following the same doubling strategy
* (from LOWER to UPPER) used in the original single‑string version.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LOWER 1024    // initial allocation size for a single line (and for the lines array)
#define UPPER 65536   // maximum increment when growing

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc != 2)
    {
        printf("Invalid number of arguments!\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // ---------- Dynamic array of lines ----------
    char **lines = NULL;          // will point to array of char*
    size_t lines_count = 0;       // number of lines stored
    size_t lines_capacity = 0;    // total slots in the array
    size_t array_increase = LOWER; // how many new slots to add when growing

    // ---------- Per‑line buffer (reused for each line) ----------
    size_t line_allocated = LOWER;
    char  *line_buffer = malloc(line_allocated);
    if (line_buffer == NULL)
    {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }

    size_t line_len = 0;          // length of the current line (without '\0')
    int c;

    // Read the file character by character
    while ((c = fgetc(file)) != EOF)
    {
        // If we hit a newline, finalise the current line
        if (c == '\n')
        {
            // Make room for the null terminator
            if (line_len >= line_allocated)
            {
                // This shouldn't happen if we grow properly, but be safe
                size_t increase = (line_allocated >= UPPER) ? UPPER : line_allocated;
                line_allocated += increase;
                line_buffer = realloc(line_buffer, line_allocated);
                if (line_buffer == NULL)
                {
                    printf("Memory allocation failed!\n");
                    fclose(file);
                    return 1;
                }
            }
            line_buffer[line_len] = '\0';

            // ----- Add the finished line to the lines array -----
            if (lines_count >= lines_capacity)
            {
                // Grow the lines array by array_increase, then double array_increase
                if (array_increase >= UPPER)
                    array_increase = UPPER;
                lines_capacity += array_increase;
                lines = realloc(lines, lines_capacity * sizeof(char *));
                if (lines == NULL)
                {
                    printf("Memory allocation failed!\n");
                    fclose(file);
                    return 1;
                }
                array_increase *= 2;
            }
            // Store a copy of the line (the buffer will be reset for the next line)
            lines[lines_count] = line_buffer;
            lines_count++;

            // Prepare a fresh buffer for the next line
            line_allocated = LOWER;
            line_buffer = malloc(line_allocated);
            if (line_buffer == NULL)
            {
                printf("Memory allocation failed!\n");
                fclose(file);
                return 1;
            }
            line_len = 0;
        }
        else
        {
            // Normal character: add it to the current line buffer
            line_buffer[line_len] = (char)c;
            line_len++;

            // Grow the line buffer if necessary
            if (line_len >= line_allocated)
            {
                size_t increase = (line_allocated >= UPPER) ? UPPER : line_allocated;
                line_allocated += increase;
                line_buffer = realloc(line_buffer, line_allocated);
                if (line_buffer == NULL)
                {
                    printf("Memory allocation failed!\n");
                    fclose(file);
                    return 1;
                }
            }
        }
    }

    // After EOF, if there are leftover characters in the buffer (file didn't end with '\n'),
    // treat them as the last line.
    if (line_len > 0)
    {
        if (line_len >= line_allocated)
        {
            size_t increase = (line_allocated >= UPPER) ? UPPER : line_allocated;
            line_allocated += increase;
            line_buffer = realloc(line_buffer, line_allocated);
            if (line_buffer == NULL)
            {
                printf("Memory allocation failed!\n");
                fclose(file);
                return 1;
            }
        }
        line_buffer[line_len] = '\0';

        // Add to lines array (grow if needed)
        if (lines_count >= lines_capacity)
        {
            if (array_increase >= UPPER)
                array_increase = UPPER;
            lines_capacity += array_increase;
            lines = realloc(lines, lines_capacity * sizeof(char *));
            if (lines == NULL)
            {
                printf("Memory allocation failed!\n");
                fclose(file);
                return 1;
            }
            array_increase *= 2;
        }
        lines[lines_count] = line_buffer;
        lines_count++;
    }
    else
    {
        // No leftover characters – the buffer we allocated for a new line is unused; free it
        free(line_buffer);
    }

    // Check for read errors
    if (ferror(file))
    {
        printf("Error reading from file!\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    // ----- Output all lines (and show line numbers) -----
    printf("File Contents (%zu lines):\n\n", lines_count);
    for (size_t i = 0; i < lines_count; i++)
    {
        printf("[%zu] %s\n", i + 1, lines[i]);
        free(lines[i]);   // free each line after printing
    }
    free(lines);

    return 0;
}
