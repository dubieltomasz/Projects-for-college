.MODEL tiny

.CODE
ORG 100h

start:
  mov ah, 9
  mov dx, offset TEXT
  int 21h

  mov ah, 4ch
  int 21h

TEXT db 'Hello world!!!$'

END start
