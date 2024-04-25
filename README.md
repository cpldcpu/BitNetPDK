
# BitNetPDK


## Project structure

```plaintext
├── include/                    # Contains the free-pdk header files
└── src/                
    ├── BitNetMCU_model.h       # MNIST model definition 
    ├── main.c                  # Main source file
    ├── Makefile
    ├── PDK_softuart.c          # Software UART implementation
    └── softuart.h              # Software UART header file
```
    
## Building Instructions

!!! **Use SDCC 4.1.0 to build. Later versions are broken.** !!!

1. Navigate to the `src/` directory.
2. Run `make flash` to build and flash the project
3. `make flash` to start the monitor
