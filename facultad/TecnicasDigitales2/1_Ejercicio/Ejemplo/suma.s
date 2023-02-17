.text
.arm
.global suma

suma:
  add   r2, r0, r1
  mov   r0, r2                    
  mov   pc, lr  