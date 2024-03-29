#ifndef PNG_IMAGE_H
#define PNG_IMAGE_H

#include <stdint.h>
#include <stdlib.h>

// Struct to represent an RGBA image
typedef struct PNG_Image {
    int width;      // Image width
    int height;     // Image height
    unsigned char* data; // Pointer to the image data
} PNG_Image;

/*
 * Loads a PNG image from a memory buffer into a custom PNG_Image structure
 */
PNG_Image* png_load_from_memory(const unsigned char *const memory, size_t memory_size);

/*
 * Loads a PNG image from a specified file path into a custom PNG_Image structure
 */
PNG_Image* png_load_from_file(const char *const filepath);

/*
 * Creates and initializes a new PNG_Image structure, allocating memory for both the structure and its associated image data
 */
PNG_Image* png_create_image(int width, int height, uint32_t rgba);

/*
 * Creates a deep copy of a PNG_Image assuming RGBA format
 */
PNG_Image* png_copy_image(const PNG_Image *const source);

/*
 * Safely deallocate memory used by a PNG_Image structure, including its image data, and then the structure itself
 */
void png_destroy_image(PNG_Image** imgPtr);

#endif // SIMPLE_IMAGE_H