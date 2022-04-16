.data
Nums:	    .asciiz	   	"Please enter positive integer array length in ascending order:"
Num:		.asciiz 	"Please enter the number:"
Searchnum: 	.asciiz		"Please enter the number to query:"
Ans:		.asciiz		"By binary search, the position number in the array is: %d"
NotFind:	.asciiz		"The number queried is not in the array!"
.align	2
PrintfPar:	.word	Ans
Printf:		.space	4
PrintfValue:	.space	1024
.text
.global main

main:
	addi r1,r0,Nums
	jal	InputUnsigned
    add  r2,r0,r1;将数组大小存在r2中
    add  r5,r0,r0;二分左边界r5
    add  r6,r0,r2;二分右边界r6
    subi r6,r6,1;右边界设为n-1
    addi r3,r0,0
InputArray:
	;r2寄存器中的值为0则跳转向ProcessPart标识的地址
    beqz r2, InputTarget       
    addi r1,r0,Num
    jal  InputUnsigned
	;将r1寄存器中的数放入r3寄存区中所存数地址的存储器中
    sw  PrintfValue(r3),r1      
    addi r3,r3,4 
    subi r2,r2,1 
	;无条件跳转向InputArray标识的指令地址
    j InputArray
InputTarget:
    addi 	r1,r0,Searchnum
    jal		InputUnsigned  
    add		r8,r0,r1;将要搜索的数存在r8中
ProcessPart:
	;r3寄存器中存字节大小
	addi r3,r0,4
    ;r9存每次的除数
    add r9,r0,2
Loop:	
    sgt r4,r5,r6;判断左边界是否小于等于右边界
    bnez r4,Notfind;左边界小于右边界
    add r7,r5,r6
    div r7,r7,r9;r7存左右边界中点
    mult r7,r7,r3
    lw r10,PrintfValue(r7);r10存数组中点的值
    seq r4,r10,r8;nums[mid]==target
    bnez r4,Output
    sgt r4,r10,r8;nums[mid]>target
	bnez r4,bigger
smaller:
	;nums[mind]<target
    div r7,r7,r3
    addi r7,r7,1
    add r5,r0,r7;更新左边界为mid+1
    j Loop
bigger:
    ;nums[mind]>target
    div r7,r7,r3
    subi r7,r7,1
    add r6,r0,r7;更新右边界为mid-1
    j Loop
Notfind:
    ;所查询的数不在数组中
	addi	r1,r0,NotFind
	sw		PrintfPar,r1
	addi	r14,r0,PrintfPar
	trap 	5
	j		over
Output:
    ;输出所查询的数在数组中的位置
	div r7,r7,r3
    add r7,r7,1
    sw Printf,r7
    addi  r14,r0,PrintfPar
    trap  5;
over:	           
	trap	 0
