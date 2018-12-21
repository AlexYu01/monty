,>, Get 2 characters from stdin
>++++++[<<-------->>-] First character minus '0' the loop ends on i = 2
++++++[<-------->-] Second character minus '0' the loop ends on i = 2
<<[
	>[
		>+>+<<- Copy second character value to i = 2 & i = 3 memory block
 	]>>
 	[
		<<+>>- Use value in i = 3 block to restore value in i = 1 block
 	]
<<<-] Loop until value in i = 0 reaches 0
>>>+++++ +++++ 4th cell (i is 3) = 10
< 3rd cell (i is 2) contains product
[->-[>+>>]>[+[-<+>]>+>>]<<<<<] end result: 3rd cell is 0  ~ 4th cell is 10 minus product % 10 ~ 5th cell is product % 10 ~ 6th cell is product / 10
>>>[>+++++ +[<++++ ++++>-]<.[-]] if 6th cell is not 0 then use 7th cell to increase it to ascii and print then decrement to 0 to exit
<[>>+++++ +[<<++++ ++++>>-]<<.>>] move to 5th cell ~ if it is not 0 then use 7th cell to increase it to ascii and print ~ move to 7th cell to exit
+++++ +++++ . print newline
