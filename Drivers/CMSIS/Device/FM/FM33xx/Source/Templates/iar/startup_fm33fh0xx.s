 ; @version  V1.1.0
 ; @date     13. June 2025
        MODULE  ?cstartup

        ; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        PUBLIC  __vector_table

        DATA

__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
        IMPORT  SystemInit
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        ;LDR     R0, =__main
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
        B NMI_Handler


        PUBWEAK HardFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
        B HardFault_Handler


        PUBWEAK SVC_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
        B SVC_Handler


        PUBWEAK PendSV_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler
        B PendSV_Handler


        PUBWEAK SysTick_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
        B SysTick_Handler


        PUBWEAK MUX0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX0_IRQHandler
        B MUX0_IRQHandler


        PUBWEAK MUX1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX1_IRQHandler
        B MUX1_IRQHandler


        PUBWEAK MUX2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX2_IRQHandler
        B MUX2_IRQHandler


        PUBWEAK MUX3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX3_IRQHandler
        B MUX3_IRQHandler


        PUBWEAK MUX4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX4_IRQHandler
        B MUX4_IRQHandler


        PUBWEAK MUX5_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX5_IRQHandler
        B MUX5_IRQHandler


        PUBWEAK MUX6_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX6_IRQHandler
        B MUX6_IRQHandler


        PUBWEAK MUX7_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX7_IRQHandler
        B MUX7_IRQHandler


        PUBWEAK MUX8_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX8_IRQHandler
        B MUX8_IRQHandler


        PUBWEAK MUX9_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX9_IRQHandler
        B MUX9_IRQHandler


        PUBWEAK MUX10_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX10_IRQHandler
        B MUX10_IRQHandler


        PUBWEAK MUX11_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX11_IRQHandler
        B MUX11_IRQHandler


        PUBWEAK MUX12_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX12_IRQHandler
        B MUX12_IRQHandler


        PUBWEAK MUX13_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX13_IRQHandler
        B MUX13_IRQHandler


        PUBWEAK MUX14_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX14_IRQHandler
        B MUX14_IRQHandler


        PUBWEAK MUX15_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX15_IRQHandler
        B MUX15_IRQHandler


        PUBWEAK MUX16_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX16_IRQHandler
        B MUX16_IRQHandler


        PUBWEAK MUX17_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX17_IRQHandler
        B MUX17_IRQHandler


        PUBWEAK MUX18_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX18_IRQHandler
        B MUX18_IRQHandler


        PUBWEAK MUX19_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX19_IRQHandler
        B MUX19_IRQHandler


        PUBWEAK MUX20_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX20_IRQHandler
        B MUX20_IRQHandler


        PUBWEAK MUX21_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX21_IRQHandler
        B MUX21_IRQHandler


        PUBWEAK MUX22_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX22_IRQHandler
        B MUX22_IRQHandler


        PUBWEAK MUX23_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX23_IRQHandler
        B MUX23_IRQHandler


        PUBWEAK MUX24_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX24_IRQHandler
        B MUX24_IRQHandler


        PUBWEAK MUX25_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX25_IRQHandler
        B MUX25_IRQHandler


        PUBWEAK MUX26_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX26_IRQHandler
        B MUX26_IRQHandler


        PUBWEAK MUX27_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX27_IRQHandler
        B MUX27_IRQHandler


        PUBWEAK MUX28_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX28_IRQHandler
        B MUX28_IRQHandler


        PUBWEAK MUX29_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX29_IRQHandler
        B MUX29_IRQHandler


        PUBWEAK MUX30_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX30_IRQHandler
        B MUX30_IRQHandler


        PUBWEAK MUX31_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MUX31_IRQHandler
        B MUX31_IRQHandler


        END