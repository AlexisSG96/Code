#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#pragma region Prototypes and Questions
/*
3. Embedded Systems Memory Allocation
Problem: Implement a simple memory pool allocator for a fixed-size memory block.
Concepts: Memory management, pointers, dynamic memory allocation.
Example: Create a fixed-size memory pool and implement functions to allocate and free memory.
*/
void init_memory_pool(void);
void* allocate_block(void);
void free_block(void* block);
#pragma endregion

int main(void)
{
    init_memory_pool();

    // Allocate some blocks
    void* block1 = allocate_block();
    void* block2 = allocate_block();

    printf("Block 1 address: %p\n", block1);
    printf("Block 2 address: %p\n", block2);

    // Free one block
    free_block(block1);
    printf("Block 1 freed\n");

    // Allocate another block
    void* block3 = allocate_block();
    printf("Block 3 address: %p\n", block3);

    return 0;
}

#pragma region Embedded Systems Memory Allocation
#define POOL_SIZE 1024  // Total memory pool size in bytes
#define BLOCK_SIZE 16   // Size of each block in bytes
#define BLOCK_COUNT (POOL_SIZE / BLOCK_SIZE) // Total number of blocks

// Memory pool structure
typedef struct {
    uint8_t pool[POOL_SIZE];     // The memory pool
    bool free_blocks[BLOCK_COUNT]; // Metadata to track free blocks (1 = free, 0 = allocated)
} MemoryPool;

// Global memory pool instance
MemoryPool mem_pool;

// Initialize the memory pool
void init_memory_pool() {
    memset(mem_pool.free_blocks, true, sizeof(mem_pool.free_blocks)); // Mark all blocks as free
}

// Allocate a block from the pool
void* allocate_block() {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        if (mem_pool.free_blocks[i]) { // Find the first free block
            mem_pool.free_blocks[i] = false; // Mark it as allocated
            return &mem_pool.pool[i * BLOCK_SIZE]; // Return pointer to the block
        }
    }
    return NULL; // No free blocks available
}

// Free a block back to the pool
void free_block(void* block) {
    uintptr_t offset = (uintptr_t)block - (uintptr_t)mem_pool.pool;
    if (offset % BLOCK_SIZE != 0 || offset < 0 || offset >= POOL_SIZE) {
        printf("Invalid block pointer!\n");
        return;
    }

    int block_index = offset / BLOCK_SIZE; // Calculate block index
    mem_pool.free_blocks[block_index] = true; // Mark block as free
}
#pragma endregion