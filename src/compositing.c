#include "compositing.h"

void blend_with_background(png_bytep img_data, int width, int height, rgba_color background_color) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            png_bytep pixel = &img_data[(y * width + x) * 4]; // 4 bytes per pixel (RGBA)

            // Alpha blending formula: new_color = alpha * foreground_color + (1 - alpha) * background_color
            double alpha = pixel[3] / 255.0; // Normalize alpha to [0, 1]
            pixel[0] = (png_byte)(alpha * pixel[0] + (1 - alpha) * background_color.red);
            pixel[1] = (png_byte)(alpha * pixel[1] + (1 - alpha) * background_color.green);
            pixel[2] = (png_byte)(alpha * pixel[2] + (1 - alpha) * background_color.blue);
            // Optionally, set the alpha to full opacity
            pixel[3] = 0xFF;
        }
    }
}