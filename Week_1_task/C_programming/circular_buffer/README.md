# Circular Buffer in C

This directory contains a simple implementation of a circular buffer (ring buffer) in C. Circular buffers are useful data structures for buffering data streams, commonly used in embedded systems, device drivers, and real-time applications.

## TO Run
         gcc circular_buffer_implementation.c -o circular
         
    Then

        ./circular
        
## Features

- Efficient fixed-size FIFO (First-In-First-Out) buffer
- Supports insertion (enqueue) and removal (dequeue) of elements
- Handles buffer wrap-around automatically
- Provides basic error handling for buffer full/empty states
- Configurable buffer size

## TO Run
         gcc circular_buffer_implementation.c -o circular

        ./circular


## Files

- `circular_buffer.c` - Source file containing the circular buffer implementation
- `circular_buffer.h` - Header file with function prototypes and data structures
- `main.c` (if present) - Example usage and test cases for the circular buffer

## Usage

1. **Include the header file** in your project:
    ```c
    #include "circular_buffer.h"
    ```

2. **Initialize the circular buffer:**
    ```c
    CircularBuffer buffer;
    cb_init(&buffer, buffer_array, BUFFER_SIZE);
    ```
    - `buffer_array` should be a pre-allocated array of the desired type and size.
    - `BUFFER_SIZE` is the number of elements in the buffer.

3. **Enqueue (add) data:**
    ```c
    if (cb_enqueue(&buffer, value) == 0) {
        // Success
    } else {
        // Buffer is full
    }
    ```

4. **Dequeue (remove) data:**
    ```c
    if (cb_dequeue(&buffer, &value) == 0) {
        // Success, value contains dequeued data
    } else {
        // Buffer is empty
    }
    ```

## Example

```c
#include "circular_buffer.h"

#define BUFFER_SIZE 8

int main() {
    int buffer_array[BUFFER_SIZE];
    CircularBuffer cb;
    cb_init(&cb, buffer_array, BUFFER_SIZE);

    cb_enqueue(&cb, 10);
    int value;
    cb_dequeue(&cb, &value); // value will be 10

    return 0;
}
```

## Applications

- Serial communication buffering
- Data stream processing
- Real-time data acquisition
- Task scheduling

## License

This project is provided as-is for educational purposes.
