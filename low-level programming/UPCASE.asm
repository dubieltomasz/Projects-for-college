.MODEL tiny

.CODE
ORG 100h
start:
  mov ah, 9
  mov dx, offset GASLIGHT1
  int 21h

  mov ah, 0Ah
  mov dx, offset GATEKEEP
  int 21h

  mov ah, 9
  mov dx, offset GASLIGHT2
  int 21h

  mov cl, [GATEKEEP+1]
  mov si, 2
  SISYPHUS:
    mov al, [GATEKEEP+si]
    cmp al, 'a'
    js CAP
    cmp al, 'z'
    js CAP
    sub al, 32

    CAP:
    mov [GATEKEEP+si], al

    add si, 1
    dec cx
  jnz SISYPHUS

  mov ah, 9
  mov dx, offset GATEKEEP+2
  int 21h

  mov ah, 4Ch
  int 21h

GASLIGHT1 db 'Write a sentence (1-254 characters):', 0Dh, 0Ah, '$'
GASLIGHT2 db 0Dh, 0Ah, 'Your sentence after changes:', 0Dh, 0Ah, '$'
GATEKEEP  db 0FFh
          db ?
          db 100h DUP('$')

END start
