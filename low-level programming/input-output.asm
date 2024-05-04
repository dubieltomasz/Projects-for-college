.MODEL tiny

.CODE
ORG 100h

start:
  mov ah, 9
  mov dx, offset PROMPT1
  int 21h

  mov ah, 0ah
  mov dx, offset BUFFER
  int 21h

  mov ah, 9
  mov dx, offset PROMPT2
  int 21h

  mov ah, 9
  mov dx, offset BUFFER+2
  int 21h

  mov ah, 4ch
  int 21h
  
BUFFER  db 6
        db ?
        db '12345_$'
PROMPT1 db 'Write some text: $'
PROMPT2 db 0dh, 0ah, 'Your text: $'
  
END start
