; printer.asm


print_string:

    mov ah, 0x0e
    start1:
        mov al, [bx]
        cmp al, 0x0
        je end1
        int 0x10
        inc bx
        jmp start1

    end1:
        ret

print_newline:

    start2:
        mov al, 0x0D
        int 0x10
        mov al, 0x0A
	int 0x10
	ret

print_hex:
	pusha
	mov cx, 4
char_loop:
	dec cx
	mov ax, dx
	shr dx, 4
	and ax, 0xF
	mov bx, HEX_OUT
	add bx, 2
	add bx, cx
	cmp ax, 0xa
	jl set_letter
	add byte [bx], 7
	jl set_letter
set_letter:
	add byte [bx], al
	cmp cx, 0
	je print_hex_done
	jmp char_loop
print_hex_done:
	mov bx, HEX_OUT
	call print_number
	popa
	ret

HEX_OUT : db '0x0000', 0
    
print_number:
	pusha

string_loop:
	mov al, [bx]
	cmp al, 0
	jne print_char
	popa
	ret

print_char:
	mov ah, 0x0e
	int 0x10
	add bx, 1
	jmp string_loop


