;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/
;V1.1.0
;13. June 2025

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000800

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000800

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size


__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; Reset Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     MUX0_IRQHandler           ; 0 MUX0
                DCD     MUX1_IRQHandler           ; 1 MUX1
                DCD     MUX2_IRQHandler           ; 2 MUX2
                DCD     MUX3_IRQHandler           ; 3 MUX3
                DCD     MUX4_IRQHandler           ; 4 MUX4
                DCD     MUX5_IRQHandler           ; 5 MUX5
                DCD     MUX6_IRQHandler           ; 6 MUX6
                DCD     MUX7_IRQHandler           ; 7 MUX7
                DCD     MUX8_IRQHandler           ; 8 MUX8
                DCD     MUX9_IRQHandler           ; 9 MUX9
                DCD     MUX10_IRQHandler          ; 10 MUX10
                DCD     MUX11_IRQHandler          ; 11 MUX11
                DCD     MUX12_IRQHandler          ; 12 MUX12
                DCD     MUX13_IRQHandler          ; 13 MUX13
                DCD     MUX14_IRQHandler          ; 14 MUX14
                DCD     MUX15_IRQHandler          ; 15 MUX15
                DCD     MUX16_IRQHandler          ; 16 MUX16
                DCD     MUX17_IRQHandler          ; 17 MUX17
                DCD     MUX18_IRQHandler          ; 18 MUX18
                DCD     MUX19_IRQHandler          ; 19 MUX19
                DCD     MUX20_IRQHandler          ; 20 MUX20
                DCD     MUX21_IRQHandler          ; 21 MUX21
                DCD     MUX22_IRQHandler          ; 22 MUX22
                DCD     MUX23_IRQHandler          ; 23 MUX23
                DCD     MUX24_IRQHandler          ; 24 MUX24
                DCD     MUX25_IRQHandler          ; 25 MUX25
                DCD     MUX26_IRQHandler          ; 26 MUX26
                DCD     MUX27_IRQHandler          ; 27 MUX27
                DCD     MUX28_IRQHandler          ; 28 MUX28
                DCD     MUX29_IRQHandler          ; 29 MUX29
                DCD     MUX30_IRQHandler          ; 30 MUX30
                DCD     MUX31_IRQHandler          ; 31 MUX31

__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP


Default_Handler PROC
                EXPORT  MUX0_IRQHandler           [WEAK]
                EXPORT  MUX1_IRQHandler           [WEAK]
                EXPORT  MUX2_IRQHandler           [WEAK]
                EXPORT  MUX3_IRQHandler           [WEAK]
                EXPORT  MUX4_IRQHandler           [WEAK]
                EXPORT  MUX5_IRQHandler           [WEAK]
                EXPORT  MUX6_IRQHandler           [WEAK]
                EXPORT  MUX7_IRQHandler           [WEAK]
                EXPORT  MUX8_IRQHandler           [WEAK]
                EXPORT  MUX9_IRQHandler           [WEAK]
                EXPORT  MUX10_IRQHandler          [WEAK]
                EXPORT  MUX11_IRQHandler          [WEAK]
                EXPORT  MUX12_IRQHandler          [WEAK]
                EXPORT  MUX13_IRQHandler          [WEAK]
                EXPORT  MUX14_IRQHandler          [WEAK]
                EXPORT  MUX15_IRQHandler          [WEAK]
                EXPORT  MUX16_IRQHandler          [WEAK]
                EXPORT  MUX17_IRQHandler          [WEAK]
                EXPORT  MUX18_IRQHandler          [WEAK]
                EXPORT  MUX19_IRQHandler          [WEAK]
                EXPORT  MUX20_IRQHandler          [WEAK]
                EXPORT  MUX21_IRQHandler          [WEAK]
                EXPORT  MUX22_IRQHandler          [WEAK]
                EXPORT  MUX23_IRQHandler          [WEAK]
                EXPORT  MUX24_IRQHandler          [WEAK]
                EXPORT  MUX25_IRQHandler          [WEAK]
                EXPORT  MUX26_IRQHandler          [WEAK]
                EXPORT  MUX27_IRQHandler          [WEAK]
                EXPORT  MUX28_IRQHandler          [WEAK]
                EXPORT  MUX29_IRQHandler          [WEAK]
                EXPORT  MUX30_IRQHandler          [WEAK]
                EXPORT  MUX31_IRQHandler          [WEAK]
MUX0_IRQHandler
MUX1_IRQHandler
MUX2_IRQHandler
MUX3_IRQHandler
MUX4_IRQHandler
MUX5_IRQHandler
MUX6_IRQHandler
MUX7_IRQHandler
MUX8_IRQHandler
MUX9_IRQHandler
MUX10_IRQHandler
MUX11_IRQHandler
MUX12_IRQHandler
MUX13_IRQHandler
MUX14_IRQHandler
MUX15_IRQHandler
MUX16_IRQHandler
MUX17_IRQHandler
MUX18_IRQHandler
MUX19_IRQHandler
MUX20_IRQHandler
MUX21_IRQHandler
MUX22_IRQHandler
MUX23_IRQHandler
MUX24_IRQHandler
MUX25_IRQHandler
MUX26_IRQHandler
MUX27_IRQHandler
MUX28_IRQHandler
MUX29_IRQHandler
MUX30_IRQHandler
MUX31_IRQHandler


                B       .
                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                ALIGN

                ENDIF


                END