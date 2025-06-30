#include <stdio.h>

#define PAGE_SIZE 4       // Each page has 4 bytes
#define NUM_PAGES 10      // Total number of pages
#define NUM_FRAMES 8      // Total number of frames in memory

int page_table[NUM_PAGES];

// Function to load a page into a frame
void load_page(int page_number, int frame_number) {
    page_table[page_number] = frame_number;
}

// Function to translate logical address to physical address
int translate(int logical_address) {
    int page_number = logical_address / PAGE_SIZE;
    int offset = logical_address % PAGE_SIZE;

    if (page_number >= NUM_PAGES) {
        printf("Invalid logical address (out of page range)\n");
        return -1;
    }

    if (page_table[page_number] == -1) {
        printf("Page Fault! Page %d not loaded into memory.\n", page_number);
        return -1;
    }

    int frame_number = page_table[page_number];
    int physical_address = (frame_number * PAGE_SIZE) + offset;
    return physical_address;
}

int main() {
    // Initialize page table with -1 (empty)
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = -1;
    }

    // Example: Load some pages into frames
    load_page(0, 3);  // Page 0 → Frame 3
    load_page(1, 5);  // Page 1 → Frame 5
    load_page(2, 1);  // Page 2 → Frame 1

    // Test logical addresses
    int logical_addresses[] = {5, 10, 2, 20};
    int n = sizeof(logical_addresses) / sizeof(logical_addresses[0]);

    printf("\nLogical Address to Physical Address Mapping:\n");
    for (int i = 0; i < n; i++) {
        int physical_address = translate(logical_addresses[i]);
        if (physical_address != -1) {
            printf("Logical Address %d → Physical Address %d\n", logical_addresses[i], physical_address);
        }
    }

    return 0;
}
