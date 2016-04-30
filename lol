
b.out:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	insb   (%dx),%es:(%rdi)
  40023a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  400246:	78 2d                	js     400275 <_init-0x1cb>
  400248:	78 38                	js     400282 <_init-0x1be>
  40024a:	36                   	ss
  40024b:	2d 36 34 2e 73       	sub    $0x732e3436,%eax
  400250:	6f                   	outsl  %ds:(%rsi),(%dx)
  400251:	2e 32 00             	xor    %cs:(%rax),%al

Disassembly of section .note.ABI-tag:

0000000000400254 <.note.ABI-tag>:
  400254:	04 00                	add    $0x0,%al
  400256:	00 00                	add    %al,(%rax)
  400258:	10 00                	adc    %al,(%rax)
  40025a:	00 00                	add    %al,(%rax)
  40025c:	01 00                	add    %eax,(%rax)
  40025e:	00 00                	add    %al,(%rax)
  400260:	47                   	rex.RXB
  400261:	4e 55                	rex.WRX push %rbp
  400263:	00 00                	add    %al,(%rax)
  400265:	00 00                	add    %al,(%rax)
  400267:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .note.gnu.build-id:

0000000000400274 <.note.gnu.build-id>:
  400274:	04 00                	add    $0x0,%al
  400276:	00 00                	add    %al,(%rax)
  400278:	14 00                	adc    $0x0,%al
  40027a:	00 00                	add    %al,(%rax)
  40027c:	03 00                	add    (%rax),%eax
  40027e:	00 00                	add    %al,(%rax)
  400280:	47                   	rex.RXB
  400281:	4e 55                	rex.WRX push %rbp
  400283:	00 68 2b             	add    %ch,0x2b(%rax)
  400286:	67 23 2b             	and    (%ebx),%ebp
  400289:	d4                   	(bad)  
  40028a:	70 98                	jo     400224 <_init-0x21c>
  40028c:	ba dd dc 16 51       	mov    $0x5116dcdd,%edx
  400291:	80 5b 58 f1          	sbbb   $0xf1,0x58(%rbx)
  400295:	73 2a                	jae    4002c1 <_init-0x17f>
  400297:	0e                   	(bad)  

Disassembly of section .hash:

0000000000400298 <.hash>:
  400298:	03 00                	add    (%rax),%eax
  40029a:	00 00                	add    %al,(%rax)
  40029c:	05 00 00 00 03       	add    $0x3000000,%eax
  4002a1:	00 00                	add    %al,(%rax)
  4002a3:	00 04 00             	add    %al,(%rax,%rax,1)
	...
  4002b2:	00 00                	add    %al,(%rax)
  4002b4:	01 00                	add    %eax,(%rax)
  4002b6:	00 00                	add    %al,(%rax)
  4002b8:	00 00                	add    %al,(%rax)
  4002ba:	00 00                	add    %al,(%rax)
  4002bc:	02 00                	add    (%rax),%al
	...

Disassembly of section .gnu.hash:

00000000004002c0 <.gnu.hash>:
  4002c0:	01 00                	add    %eax,(%rax)
  4002c2:	00 00                	add    %al,(%rax)
  4002c4:	01 00                	add    %eax,(%rax)
  4002c6:	00 00                	add    %al,(%rax)
  4002c8:	01 00                	add    %eax,(%rax)
	...

Disassembly of section .dynsym:

00000000004002e0 <.dynsym>:
	...
  4002f8:	10 00                	adc    %al,(%rax)
  4002fa:	00 00                	add    %al,(%rax)
  4002fc:	12 00                	adc    (%rax),%al
	...
  40030e:	00 00                	add    %al,(%rax)
  400310:	15 00 00 00 12       	adc    $0x12000000,%eax
	...
  400325:	00 00                	add    %al,(%rax)
  400327:	00 27                	add    %ah,(%rdi)
  400329:	00 00                	add    %al,(%rax)
  40032b:	00 20                	add    %ah,(%rax)
	...
  40033d:	00 00                	add    %al,(%rax)
  40033f:	00 0b                	add    %cl,(%rbx)
  400341:	00 00                	add    %al,(%rax)
  400343:	00 12                	add    %dl,(%rdx)
	...

Disassembly of section .dynstr:

0000000000400358 <.dynstr>:
  400358:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  40035c:	63 2e                	movslq (%rsi),%ebp
  40035e:	73 6f                	jae    4003cf <_init-0x71>
  400360:	2e 36 00 65 78       	cs add %ah,%cs:%ss:0x78(%rbp)
  400365:	69 74 00 70 75 74 73 	imul   $0x737475,0x70(%rax,%rax,1),%esi
  40036c:	00 
  40036d:	5f                   	pop    %rdi
  40036e:	5f                   	pop    %rdi
  40036f:	6c                   	insb   (%dx),%es:(%rdi)
  400370:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  400377:	72 74                	jb     4003ed <_init-0x53>
  400379:	5f                   	pop    %rdi
  40037a:	6d                   	insl   (%dx),%es:(%rdi)
  40037b:	61                   	(bad)  
  40037c:	69 6e 00 5f 5f 67 6d 	imul   $0x6d675f5f,0x0(%rsi),%ebp
  400383:	6f                   	outsl  %ds:(%rsi),(%dx)
  400384:	6e                   	outsb  %ds:(%rsi),(%dx)
  400385:	5f                   	pop    %rdi
  400386:	73 74                	jae    4003fc <_init-0x44>
  400388:	61                   	(bad)  
  400389:	72 74                	jb     4003ff <_init-0x41>
  40038b:	5f                   	pop    %rdi
  40038c:	5f                   	pop    %rdi
  40038d:	00 47 4c             	add    %al,0x4c(%rdi)
  400390:	49                   	rex.WB
  400391:	42                   	rex.X
  400392:	43 5f                	rex.XB pop %r15
  400394:	32 2e                	xor    (%rsi),%ch
  400396:	32 2e                	xor    (%rsi),%ch
  400398:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

000000000040039a <.gnu.version>:
  40039a:	00 00                	add    %al,(%rax)
  40039c:	02 00                	add    (%rax),%al
  40039e:	02 00                	add    (%rax),%al
  4003a0:	00 00                	add    %al,(%rax)
  4003a2:	02 00                	add    (%rax),%al

Disassembly of section .gnu.version_r:

00000000004003a8 <.gnu.version_r>:
  4003a8:	01 00                	add    %eax,(%rax)
  4003aa:	01 00                	add    %eax,(%rax)
  4003ac:	01 00                	add    %eax,(%rax)
  4003ae:	00 00                	add    %al,(%rax)
  4003b0:	10 00                	adc    %al,(%rax)
  4003b2:	00 00                	add    %al,(%rax)
  4003b4:	00 00                	add    %al,(%rax)
  4003b6:	00 00                	add    %al,(%rax)
  4003b8:	75 1a                	jne    4003d4 <_init-0x6c>
  4003ba:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  4003c0:	36 00 00             	add    %al,%ss:(%rax)
  4003c3:	00 00                	add    %al,(%rax)
  4003c5:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

00000000004003c8 <.rela.dyn>:
  4003c8:	f8                   	clc    
  4003c9:	0f 60 00             	punpcklbw (%rax),%mm0
  4003cc:	00 00                	add    %al,(%rax)
  4003ce:	00 00                	add    %al,(%rax)
  4003d0:	06                   	(bad)  
  4003d1:	00 00                	add    %al,(%rax)
  4003d3:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .rela.plt:

00000000004003e0 <.rela.plt>:
  4003e0:	18 10                	sbb    %dl,(%rax)
  4003e2:	60                   	(bad)  
  4003e3:	00 00                	add    %al,(%rax)
  4003e5:	00 00                	add    %al,(%rax)
  4003e7:	00 07                	add    %al,(%rdi)
  4003e9:	00 00                	add    %al,(%rax)
  4003eb:	00 01                	add    %al,(%rcx)
	...
  4003f5:	00 00                	add    %al,(%rax)
  4003f7:	00 20                	add    %ah,(%rax)
  4003f9:	10 60 00             	adc    %ah,0x0(%rax)
  4003fc:	00 00                	add    %al,(%rax)
  4003fe:	00 00                	add    %al,(%rax)
  400400:	07                   	(bad)  
  400401:	00 00                	add    %al,(%rax)
  400403:	00 02                	add    %al,(%rdx)
	...
  40040d:	00 00                	add    %al,(%rax)
  40040f:	00 28                	add    %ch,(%rax)
  400411:	10 60 00             	adc    %ah,0x0(%rax)
  400414:	00 00                	add    %al,(%rax)
  400416:	00 00                	add    %al,(%rax)
  400418:	07                   	(bad)  
  400419:	00 00                	add    %al,(%rax)
  40041b:	00 03                	add    %al,(%rbx)
	...
  400425:	00 00                	add    %al,(%rax)
  400427:	00 30                	add    %dh,(%rax)
  400429:	10 60 00             	adc    %ah,0x0(%rax)
  40042c:	00 00                	add    %al,(%rax)
  40042e:	00 00                	add    %al,(%rax)
  400430:	07                   	(bad)  
  400431:	00 00                	add    %al,(%rax)
  400433:	00 04 00             	add    %al,(%rax,%rax,1)
	...

Disassembly of section .init:

0000000000400440 <_init>:
  400440:	48 83 ec 08          	sub    $0x8,%rsp
  400444:	48 8b 05 ad 0b 20 00 	mov    0x200bad(%rip),%rax        # 600ff8 <_DYNAMIC+0x1e0>
  40044b:	48 85 c0             	test   %rax,%rax
  40044e:	74 05                	je     400455 <_init+0x15>
  400450:	e8 3b 00 00 00       	callq  400490 <__gmon_start__@plt>
  400455:	48 83 c4 08          	add    $0x8,%rsp
  400459:	c3                   	retq   

Disassembly of section .plt:

0000000000400460 <puts@plt-0x10>:
  400460:	ff 35 a2 0b 20 00    	pushq  0x200ba2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400466:	ff 25 a4 0b 20 00    	jmpq   *0x200ba4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40046c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400470 <puts@plt>:
  400470:	ff 25 a2 0b 20 00    	jmpq   *0x200ba2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400476:	68 00 00 00 00       	pushq  $0x0
  40047b:	e9 e0 ff ff ff       	jmpq   400460 <_init+0x20>

0000000000400480 <__libc_start_main@plt>:
  400480:	ff 25 9a 0b 20 00    	jmpq   *0x200b9a(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400486:	68 01 00 00 00       	pushq  $0x1
  40048b:	e9 d0 ff ff ff       	jmpq   400460 <_init+0x20>

0000000000400490 <__gmon_start__@plt>:
  400490:	ff 25 92 0b 20 00    	jmpq   *0x200b92(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400496:	68 02 00 00 00       	pushq  $0x2
  40049b:	e9 c0 ff ff ff       	jmpq   400460 <_init+0x20>

00000000004004a0 <exit@plt>:
  4004a0:	ff 25 8a 0b 20 00    	jmpq   *0x200b8a(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4004a6:	68 03 00 00 00       	pushq  $0x3
  4004ab:	e9 b0 ff ff ff       	jmpq   400460 <_init+0x20>

Disassembly of section .text:

00000000004004b0 <_start>:
  4004b0:	31 ed                	xor    %ebp,%ebp
  4004b2:	49 89 d1             	mov    %rdx,%r9
  4004b5:	5e                   	pop    %rsi
  4004b6:	48 89 e2             	mov    %rsp,%rdx
  4004b9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4004bd:	50                   	push   %rax
  4004be:	54                   	push   %rsp
  4004bf:	49 c7 c0 50 06 40 00 	mov    $0x400650,%r8
  4004c6:	48 c7 c1 e0 05 40 00 	mov    $0x4005e0,%rcx
  4004cd:	48 c7 c7 bd 05 40 00 	mov    $0x4005bd,%rdi
  4004d4:	e8 a7 ff ff ff       	callq  400480 <__libc_start_main@plt>
  4004d9:	f4                   	hlt    
  4004da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004004e0 <deregister_tm_clones>:
  4004e0:	b8 4f 10 60 00       	mov    $0x60104f,%eax
  4004e5:	55                   	push   %rbp
  4004e6:	48 2d 48 10 60 00    	sub    $0x601048,%rax
  4004ec:	48 83 f8 0e          	cmp    $0xe,%rax
  4004f0:	48 89 e5             	mov    %rsp,%rbp
  4004f3:	77 02                	ja     4004f7 <deregister_tm_clones+0x17>
  4004f5:	5d                   	pop    %rbp
  4004f6:	c3                   	retq   
  4004f7:	b8 00 00 00 00       	mov    $0x0,%eax
  4004fc:	48 85 c0             	test   %rax,%rax
  4004ff:	74 f4                	je     4004f5 <deregister_tm_clones+0x15>
  400501:	5d                   	pop    %rbp
  400502:	bf 48 10 60 00       	mov    $0x601048,%edi
  400507:	ff e0                	jmpq   *%rax
  400509:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400510 <register_tm_clones>:
  400510:	b8 48 10 60 00       	mov    $0x601048,%eax
  400515:	55                   	push   %rbp
  400516:	48 2d 48 10 60 00    	sub    $0x601048,%rax
  40051c:	48 c1 f8 03          	sar    $0x3,%rax
  400520:	48 89 e5             	mov    %rsp,%rbp
  400523:	48 89 c2             	mov    %rax,%rdx
  400526:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40052a:	48 01 d0             	add    %rdx,%rax
  40052d:	48 d1 f8             	sar    %rax
  400530:	75 02                	jne    400534 <register_tm_clones+0x24>
  400532:	5d                   	pop    %rbp
  400533:	c3                   	retq   
  400534:	ba 00 00 00 00       	mov    $0x0,%edx
  400539:	48 85 d2             	test   %rdx,%rdx
  40053c:	74 f4                	je     400532 <register_tm_clones+0x22>
  40053e:	5d                   	pop    %rbp
  40053f:	48 89 c6             	mov    %rax,%rsi
  400542:	bf 48 10 60 00       	mov    $0x601048,%edi
  400547:	ff e2                	jmpq   *%rdx
  400549:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400550 <__do_global_dtors_aux>:
  400550:	80 3d f1 0a 20 00 00 	cmpb   $0x0,0x200af1(%rip)        # 601048 <__TMC_END__>
  400557:	75 11                	jne    40056a <__do_global_dtors_aux+0x1a>
  400559:	55                   	push   %rbp
  40055a:	48 89 e5             	mov    %rsp,%rbp
  40055d:	e8 7e ff ff ff       	callq  4004e0 <deregister_tm_clones>
  400562:	5d                   	pop    %rbp
  400563:	c6 05 de 0a 20 00 01 	movb   $0x1,0x200ade(%rip)        # 601048 <__TMC_END__>
  40056a:	f3 c3                	repz retq 
  40056c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400570 <frame_dummy>:
  400570:	48 83 3d 98 08 20 00 	cmpq   $0x0,0x200898(%rip)        # 600e10 <__JCR_END__>
  400577:	00 
  400578:	74 1e                	je     400598 <frame_dummy+0x28>
  40057a:	b8 00 00 00 00       	mov    $0x0,%eax
  40057f:	48 85 c0             	test   %rax,%rax
  400582:	74 14                	je     400598 <frame_dummy+0x28>
  400584:	55                   	push   %rbp
  400585:	bf 10 0e 60 00       	mov    $0x600e10,%edi
  40058a:	48 89 e5             	mov    %rsp,%rbp
  40058d:	ff d0                	callq  *%rax
  40058f:	5d                   	pop    %rbp
  400590:	e9 7b ff ff ff       	jmpq   400510 <register_tm_clones>
  400595:	0f 1f 00             	nopl   (%rax)
  400598:	e9 73 ff ff ff       	jmpq   400510 <register_tm_clones>

000000000040059d <toto>:
  40059d:	55                   	push   %rbp
  40059e:	48 89 e5             	mov    %rsp,%rbp
  4005a1:	bf 64 06 40 00       	mov    $0x400664,%edi
  4005a6:	e8 c5 fe ff ff       	callq  400470 <puts@plt>
  4005ab:	5d                   	pop    %rbp
  4005ac:	c3                   	retq   

00000000004005ad <tutu>:
  4005ad:	55                   	push   %rbp
  4005ae:	48 89 e5             	mov    %rsp,%rbp
  4005b1:	bf 78 06 40 00       	mov    $0x400678,%edi
  4005b6:	e8 b5 fe ff ff       	callq  400470 <puts@plt>
  4005bb:	5d                   	pop    %rbp
  4005bc:	c3                   	retq   

00000000004005bd <main>:
  4005bd:	55                   	push   %rbp
  4005be:	48 89 e5             	mov    %rsp,%rbp
  4005c1:	e8 d7 ff ff ff       	callq  40059d <toto>
  4005c6:	e8 e2 ff ff ff       	callq  4005ad <tutu>
  4005cb:	bf 00 00 00 00       	mov    $0x0,%edi
  4005d0:	e8 cb fe ff ff       	callq  4004a0 <exit@plt>
  4005d5:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4005dc:	00 00 00 
  4005df:	90                   	nop

00000000004005e0 <__libc_csu_init>:
  4005e0:	41 57                	push   %r15
  4005e2:	41 89 ff             	mov    %edi,%r15d
  4005e5:	41 56                	push   %r14
  4005e7:	49 89 f6             	mov    %rsi,%r14
  4005ea:	41 55                	push   %r13
  4005ec:	49 89 d5             	mov    %rdx,%r13
  4005ef:	41 54                	push   %r12
  4005f1:	4c 8d 25 08 08 20 00 	lea    0x200808(%rip),%r12        # 600e00 <__frame_dummy_init_array_entry>
  4005f8:	55                   	push   %rbp
  4005f9:	48 8d 2d 08 08 20 00 	lea    0x200808(%rip),%rbp        # 600e08 <__init_array_end>
  400600:	53                   	push   %rbx
  400601:	4c 29 e5             	sub    %r12,%rbp
  400604:	31 db                	xor    %ebx,%ebx
  400606:	48 c1 fd 03          	sar    $0x3,%rbp
  40060a:	48 83 ec 08          	sub    $0x8,%rsp
  40060e:	e8 2d fe ff ff       	callq  400440 <_init>
  400613:	48 85 ed             	test   %rbp,%rbp
  400616:	74 1e                	je     400636 <__libc_csu_init+0x56>
  400618:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40061f:	00 
  400620:	4c 89 ea             	mov    %r13,%rdx
  400623:	4c 89 f6             	mov    %r14,%rsi
  400626:	44 89 ff             	mov    %r15d,%edi
  400629:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40062d:	48 83 c3 01          	add    $0x1,%rbx
  400631:	48 39 eb             	cmp    %rbp,%rbx
  400634:	75 ea                	jne    400620 <__libc_csu_init+0x40>
  400636:	48 83 c4 08          	add    $0x8,%rsp
  40063a:	5b                   	pop    %rbx
  40063b:	5d                   	pop    %rbp
  40063c:	41 5c                	pop    %r12
  40063e:	41 5d                	pop    %r13
  400640:	41 5e                	pop    %r14
  400642:	41 5f                	pop    %r15
  400644:	c3                   	retq   
  400645:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  40064c:	00 00 00 00 

0000000000400650 <__libc_csu_fini>:
  400650:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400654 <_fini>:
  400654:	48 83 ec 08          	sub    $0x8,%rsp
  400658:	48 83 c4 08          	add    $0x8,%rsp
  40065c:	c3                   	retq   

Disassembly of section .rodata:

0000000000400660 <_IO_stdin_used>:
  400660:	01 00                	add    %eax,(%rax)
  400662:	02 00                	add    (%rax),%al
  400664:	6a 65                	pushq  $0x65
  400666:	20 73 75             	and    %dh,0x75(%rbx)
  400669:	69 73 20 64 61 6e 73 	imul   $0x736e6164,0x20(%rbx),%esi
  400670:	20 74 6f 74          	and    %dh,0x74(%rdi,%rbp,2)
  400674:	6f                   	outsl  %ds:(%rsi),(%dx)
  400675:	28 29                	sub    %ch,(%rcx)
  400677:	00 6a 65             	add    %ch,0x65(%rdx)
  40067a:	20 73 75             	and    %dh,0x75(%rbx)
  40067d:	69 73 20 64 61 6e 73 	imul   $0x736e6164,0x20(%rbx),%esi
  400684:	20 74 75 74          	and    %dh,0x74(%rbp,%rsi,2)
  400688:	75 28                	jne    4006b2 <_IO_stdin_used+0x52>
  40068a:	29 00                	sub    %eax,(%rax)

Disassembly of section .eh_frame_hdr:

000000000040068c <.eh_frame_hdr>:
  40068c:	01 1b                	add    %ebx,(%rbx)
  40068e:	03 3b                	add    (%rbx),%edi
  400690:	40 00 00             	add    %al,(%rax)
  400693:	00 07                	add    %al,(%rdi)
  400695:	00 00                	add    %al,(%rax)
  400697:	00 d4                	add    %dl,%ah
  400699:	fd                   	std    
  40069a:	ff                   	(bad)  
  40069b:	ff 8c 00 00 00 24 fe 	decl   -0x1dc0000(%rax,%rax,1)
  4006a2:	ff                   	(bad)  
  4006a3:	ff 5c 00 00          	lcallq *0x0(%rax,%rax,1)
  4006a7:	00 11                	add    %dl,(%rcx)
  4006a9:	ff                   	(bad)  
  4006aa:	ff                   	(bad)  
  4006ab:	ff b4 00 00 00 21 ff 	pushq  -0xdf0000(%rax,%rax,1)
  4006b2:	ff                   	(bad)  
  4006b3:	ff d4                	callq  *%rsp
  4006b5:	00 00                	add    %al,(%rax)
  4006b7:	00 31                	add    %dh,(%rcx)
  4006b9:	ff                   	(bad)  
  4006ba:	ff                   	(bad)  
  4006bb:	ff f4                	push   %rsp
  4006bd:	00 00                	add    %al,(%rax)
  4006bf:	00 54 ff ff          	add    %dl,-0x1(%rdi,%rdi,8)
  4006c3:	ff 14 01             	callq  *(%rcx,%rax,1)
  4006c6:	00 00                	add    %al,(%rax)
  4006c8:	c4                   	(bad)  
  4006c9:	ff                   	(bad)  
  4006ca:	ff                   	(bad)  
  4006cb:	ff 5c 01 00          	lcallq *0x0(%rcx,%rax,1)
	...

Disassembly of section .eh_frame:

00000000004006d0 <__FRAME_END__-0x130>:
  4006d0:	14 00                	adc    $0x0,%al
  4006d2:	00 00                	add    %al,(%rax)
  4006d4:	00 00                	add    %al,(%rax)
  4006d6:	00 00                	add    %al,(%rax)
  4006d8:	01 7a 52             	add    %edi,0x52(%rdx)
  4006db:	00 01                	add    %al,(%rcx)
  4006dd:	78 10                	js     4006ef <_IO_stdin_used+0x8f>
  4006df:	01 1b                	add    %ebx,(%rbx)
  4006e1:	0c 07                	or     $0x7,%al
  4006e3:	08 90 01 07 10 14    	or     %dl,0x14100701(%rax)
  4006e9:	00 00                	add    %al,(%rax)
  4006eb:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4006ee:	00 00                	add    %al,(%rax)
  4006f0:	c0 fd ff             	sar    $0xff,%ch
  4006f3:	ff 2a                	ljmpq  *(%rdx)
	...
  4006fd:	00 00                	add    %al,(%rax)
  4006ff:	00 14 00             	add    %dl,(%rax,%rax,1)
  400702:	00 00                	add    %al,(%rax)
  400704:	00 00                	add    %al,(%rax)
  400706:	00 00                	add    %al,(%rax)
  400708:	01 7a 52             	add    %edi,0x52(%rdx)
  40070b:	00 01                	add    %al,(%rcx)
  40070d:	78 10                	js     40071f <_IO_stdin_used+0xbf>
  40070f:	01 1b                	add    %ebx,(%rbx)
  400711:	0c 07                	or     $0x7,%al
  400713:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
  400719:	00 00                	add    %al,(%rax)
  40071b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40071e:	00 00                	add    %al,(%rax)
  400720:	40 fd                	rex std 
  400722:	ff                   	(bad)  
  400723:	ff 50 00             	callq  *0x0(%rax)
  400726:	00 00                	add    %al,(%rax)
  400728:	00 0e                	add    %cl,(%rsi)
  40072a:	10 46 0e             	adc    %al,0xe(%rsi)
  40072d:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  400730:	0b 77 08             	or     0x8(%rdi),%esi
  400733:	80 00 3f             	addb   $0x3f,(%rax)
  400736:	1a 3b                	sbb    (%rbx),%bh
  400738:	2a 33                	sub    (%rbx),%dh
  40073a:	24 22                	and    $0x22,%al
  40073c:	00 00                	add    %al,(%rax)
  40073e:	00 00                	add    %al,(%rax)
  400740:	1c 00                	sbb    $0x0,%al
  400742:	00 00                	add    %al,(%rax)
  400744:	44 00 00             	add    %r8b,(%rax)
  400747:	00 55 fe             	add    %dl,-0x2(%rbp)
  40074a:	ff                   	(bad)  
  40074b:	ff 10                	callq  *(%rax)
  40074d:	00 00                	add    %al,(%rax)
  40074f:	00 00                	add    %al,(%rax)
  400751:	41 0e                	rex.B (bad) 
  400753:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400759:	4b 0c 07             	rex.WXB or $0x7,%al
  40075c:	08 00                	or     %al,(%rax)
  40075e:	00 00                	add    %al,(%rax)
  400760:	1c 00                	sbb    $0x0,%al
  400762:	00 00                	add    %al,(%rax)
  400764:	64 00 00             	add    %al,%fs:(%rax)
  400767:	00 45 fe             	add    %al,-0x2(%rbp)
  40076a:	ff                   	(bad)  
  40076b:	ff 10                	callq  *(%rax)
  40076d:	00 00                	add    %al,(%rax)
  40076f:	00 00                	add    %al,(%rax)
  400771:	41 0e                	rex.B (bad) 
  400773:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400779:	4b 0c 07             	rex.WXB or $0x7,%al
  40077c:	08 00                	or     %al,(%rax)
  40077e:	00 00                	add    %al,(%rax)
  400780:	1c 00                	sbb    $0x0,%al
  400782:	00 00                	add    %al,(%rax)
  400784:	84 00                	test   %al,(%rax)
  400786:	00 00                	add    %al,(%rax)
  400788:	35 fe ff ff 18       	xor    $0x18fffffe,%eax
  40078d:	00 00                	add    %al,(%rax)
  40078f:	00 00                	add    %al,(%rax)
  400791:	41 0e                	rex.B (bad) 
  400793:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400799:	00 00                	add    %al,(%rax)
  40079b:	00 00                	add    %al,(%rax)
  40079d:	00 00                	add    %al,(%rax)
  40079f:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
  4007a3:	00 a4 00 00 00 38 fe 	add    %ah,-0x1c80000(%rax,%rax,1)
  4007aa:	ff                   	(bad)  
  4007ab:	ff 65 00             	jmpq   *0x0(%rbp)
  4007ae:	00 00                	add    %al,(%rax)
  4007b0:	00 42 0e             	add    %al,0xe(%rdx)
  4007b3:	10 8f 02 45 0e 18    	adc    %cl,0x180e4502(%rdi)
  4007b9:	8e 03                	mov    (%rbx),%es
  4007bb:	45 0e                	rex.RB (bad) 
  4007bd:	20 8d 04 45 0e 28    	and    %cl,0x280e4504(%rbp)
  4007c3:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86701611 <_end+0xffffffff861005c1>
  4007c9:	06                   	(bad)  
  4007ca:	48 0e                	rex.W (bad) 
  4007cc:	38 83 07 4d 0e 40    	cmp    %al,0x400e4d07(%rbx)
  4007d2:	6c                   	insb   (%dx),%es:(%rdi)
  4007d3:	0e                   	(bad)  
  4007d4:	38 41 0e             	cmp    %al,0xe(%rcx)
  4007d7:	30 41 0e             	xor    %al,0xe(%rcx)
  4007da:	28 42 0e             	sub    %al,0xe(%rdx)
  4007dd:	20 42 0e             	and    %al,0xe(%rdx)
  4007e0:	18 42 0e             	sbb    %al,0xe(%rdx)
  4007e3:	10 42 0e             	adc    %al,0xe(%rdx)
  4007e6:	08 00                	or     %al,(%rax)
  4007e8:	14 00                	adc    $0x0,%al
  4007ea:	00 00                	add    %al,(%rax)
  4007ec:	ec                   	in     (%dx),%al
  4007ed:	00 00                	add    %al,(%rax)
  4007ef:	00 60 fe             	add    %ah,-0x2(%rax)
  4007f2:	ff                   	(bad)  
  4007f3:	ff 02                	incl   (%rdx)
	...

0000000000400800 <__FRAME_END__>:
  400800:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000600e00 <__frame_dummy_init_array_entry>:
  600e00:	70 05                	jo     600e07 <__frame_dummy_init_array_entry+0x7>
  600e02:	40 00 00             	add    %al,(%rax)
  600e05:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000600e08 <__do_global_dtors_aux_fini_array_entry>:
  600e08:	50                   	push   %rax
  600e09:	05 40 00 00 00       	add    $0x40,%eax
	...

Disassembly of section .jcr:

0000000000600e10 <__JCR_END__>:
	...

Disassembly of section .dynamic:

0000000000600e18 <_DYNAMIC>:
  600e18:	01 00                	add    %eax,(%rax)
  600e1a:	00 00                	add    %al,(%rax)
  600e1c:	00 00                	add    %al,(%rax)
  600e1e:	00 00                	add    %al,(%rax)
  600e20:	01 00                	add    %eax,(%rax)
  600e22:	00 00                	add    %al,(%rax)
  600e24:	00 00                	add    %al,(%rax)
  600e26:	00 00                	add    %al,(%rax)
  600e28:	0c 00                	or     $0x0,%al
  600e2a:	00 00                	add    %al,(%rax)
  600e2c:	00 00                	add    %al,(%rax)
  600e2e:	00 00                	add    %al,(%rax)
  600e30:	40 04 40             	add    $0x40,%al
  600e33:	00 00                	add    %al,(%rax)
  600e35:	00 00                	add    %al,(%rax)
  600e37:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 600e3d <_DYNAMIC+0x25>
  600e3d:	00 00                	add    %al,(%rax)
  600e3f:	00 54 06 40          	add    %dl,0x40(%rsi,%rax,1)
  600e43:	00 00                	add    %al,(%rax)
  600e45:	00 00                	add    %al,(%rax)
  600e47:	00 19                	add    %bl,(%rcx)
	...
  600e51:	0e                   	(bad)  
  600e52:	60                   	(bad)  
  600e53:	00 00                	add    %al,(%rax)
  600e55:	00 00                	add    %al,(%rax)
  600e57:	00 1b                	add    %bl,(%rbx)
  600e59:	00 00                	add    %al,(%rax)
  600e5b:	00 00                	add    %al,(%rax)
  600e5d:	00 00                	add    %al,(%rax)
  600e5f:	00 08                	add    %cl,(%rax)
  600e61:	00 00                	add    %al,(%rax)
  600e63:	00 00                	add    %al,(%rax)
  600e65:	00 00                	add    %al,(%rax)
  600e67:	00 1a                	add    %bl,(%rdx)
  600e69:	00 00                	add    %al,(%rax)
  600e6b:	00 00                	add    %al,(%rax)
  600e6d:	00 00                	add    %al,(%rax)
  600e6f:	00 08                	add    %cl,(%rax)
  600e71:	0e                   	(bad)  
  600e72:	60                   	(bad)  
  600e73:	00 00                	add    %al,(%rax)
  600e75:	00 00                	add    %al,(%rax)
  600e77:	00 1c 00             	add    %bl,(%rax,%rax,1)
  600e7a:	00 00                	add    %al,(%rax)
  600e7c:	00 00                	add    %al,(%rax)
  600e7e:	00 00                	add    %al,(%rax)
  600e80:	08 00                	or     %al,(%rax)
  600e82:	00 00                	add    %al,(%rax)
  600e84:	00 00                	add    %al,(%rax)
  600e86:	00 00                	add    %al,(%rax)
  600e88:	04 00                	add    $0x0,%al
  600e8a:	00 00                	add    %al,(%rax)
  600e8c:	00 00                	add    %al,(%rax)
  600e8e:	00 00                	add    %al,(%rax)
  600e90:	98                   	cwtl   
  600e91:	02 40 00             	add    0x0(%rax),%al
  600e94:	00 00                	add    %al,(%rax)
  600e96:	00 00                	add    %al,(%rax)
  600e98:	f5                   	cmc    
  600e99:	fe                   	(bad)  
  600e9a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600e9d:	00 00                	add    %al,(%rax)
  600e9f:	00 c0                	add    %al,%al
  600ea1:	02 40 00             	add    0x0(%rax),%al
  600ea4:	00 00                	add    %al,(%rax)
  600ea6:	00 00                	add    %al,(%rax)
  600ea8:	05 00 00 00 00       	add    $0x0,%eax
  600ead:	00 00                	add    %al,(%rax)
  600eaf:	00 58 03             	add    %bl,0x3(%rax)
  600eb2:	40 00 00             	add    %al,(%rax)
  600eb5:	00 00                	add    %al,(%rax)
  600eb7:	00 06                	add    %al,(%rsi)
  600eb9:	00 00                	add    %al,(%rax)
  600ebb:	00 00                	add    %al,(%rax)
  600ebd:	00 00                	add    %al,(%rax)
  600ebf:	00 e0                	add    %ah,%al
  600ec1:	02 40 00             	add    0x0(%rax),%al
  600ec4:	00 00                	add    %al,(%rax)
  600ec6:	00 00                	add    %al,(%rax)
  600ec8:	0a 00                	or     (%rax),%al
  600eca:	00 00                	add    %al,(%rax)
  600ecc:	00 00                	add    %al,(%rax)
  600ece:	00 00                	add    %al,(%rax)
  600ed0:	42 00 00             	rex.X add %al,(%rax)
  600ed3:	00 00                	add    %al,(%rax)
  600ed5:	00 00                	add    %al,(%rax)
  600ed7:	00 0b                	add    %cl,(%rbx)
  600ed9:	00 00                	add    %al,(%rax)
  600edb:	00 00                	add    %al,(%rax)
  600edd:	00 00                	add    %al,(%rax)
  600edf:	00 18                	add    %bl,(%rax)
  600ee1:	00 00                	add    %al,(%rax)
  600ee3:	00 00                	add    %al,(%rax)
  600ee5:	00 00                	add    %al,(%rax)
  600ee7:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 600eed <_DYNAMIC+0xd5>
	...
  600ef5:	00 00                	add    %al,(%rax)
  600ef7:	00 03                	add    %al,(%rbx)
	...
  600f01:	10 60 00             	adc    %ah,0x0(%rax)
  600f04:	00 00                	add    %al,(%rax)
  600f06:	00 00                	add    %al,(%rax)
  600f08:	02 00                	add    (%rax),%al
  600f0a:	00 00                	add    %al,(%rax)
  600f0c:	00 00                	add    %al,(%rax)
  600f0e:	00 00                	add    %al,(%rax)
  600f10:	60                   	(bad)  
  600f11:	00 00                	add    %al,(%rax)
  600f13:	00 00                	add    %al,(%rax)
  600f15:	00 00                	add    %al,(%rax)
  600f17:	00 14 00             	add    %dl,(%rax,%rax,1)
  600f1a:	00 00                	add    %al,(%rax)
  600f1c:	00 00                	add    %al,(%rax)
  600f1e:	00 00                	add    %al,(%rax)
  600f20:	07                   	(bad)  
  600f21:	00 00                	add    %al,(%rax)
  600f23:	00 00                	add    %al,(%rax)
  600f25:	00 00                	add    %al,(%rax)
  600f27:	00 17                	add    %dl,(%rdi)
  600f29:	00 00                	add    %al,(%rax)
  600f2b:	00 00                	add    %al,(%rax)
  600f2d:	00 00                	add    %al,(%rax)
  600f2f:	00 e0                	add    %ah,%al
  600f31:	03 40 00             	add    0x0(%rax),%eax
  600f34:	00 00                	add    %al,(%rax)
  600f36:	00 00                	add    %al,(%rax)
  600f38:	07                   	(bad)  
  600f39:	00 00                	add    %al,(%rax)
  600f3b:	00 00                	add    %al,(%rax)
  600f3d:	00 00                	add    %al,(%rax)
  600f3f:	00 c8                	add    %cl,%al
  600f41:	03 40 00             	add    0x0(%rax),%eax
  600f44:	00 00                	add    %al,(%rax)
  600f46:	00 00                	add    %al,(%rax)
  600f48:	08 00                	or     %al,(%rax)
  600f4a:	00 00                	add    %al,(%rax)
  600f4c:	00 00                	add    %al,(%rax)
  600f4e:	00 00                	add    %al,(%rax)
  600f50:	18 00                	sbb    %al,(%rax)
  600f52:	00 00                	add    %al,(%rax)
  600f54:	00 00                	add    %al,(%rax)
  600f56:	00 00                	add    %al,(%rax)
  600f58:	09 00                	or     %eax,(%rax)
  600f5a:	00 00                	add    %al,(%rax)
  600f5c:	00 00                	add    %al,(%rax)
  600f5e:	00 00                	add    %al,(%rax)
  600f60:	18 00                	sbb    %al,(%rax)
  600f62:	00 00                	add    %al,(%rax)
  600f64:	00 00                	add    %al,(%rax)
  600f66:	00 00                	add    %al,(%rax)
  600f68:	fe                   	(bad)  
  600f69:	ff                   	(bad)  
  600f6a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600f6d:	00 00                	add    %al,(%rax)
  600f6f:	00 a8 03 40 00 00    	add    %ch,0x4003(%rax)
  600f75:	00 00                	add    %al,(%rax)
  600f77:	00 ff                	add    %bh,%bh
  600f79:	ff                   	(bad)  
  600f7a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600f7d:	00 00                	add    %al,(%rax)
  600f7f:	00 01                	add    %al,(%rcx)
  600f81:	00 00                	add    %al,(%rax)
  600f83:	00 00                	add    %al,(%rax)
  600f85:	00 00                	add    %al,(%rax)
  600f87:	00 f0                	add    %dh,%al
  600f89:	ff                   	(bad)  
  600f8a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600f8d:	00 00                	add    %al,(%rax)
  600f8f:	00 9a 03 40 00 00    	add    %bl,0x4003(%rdx)
	...

Disassembly of section .got:

0000000000600ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
  601000:	18 0e                	sbb    %cl,(%rsi)
  601002:	60                   	(bad)  
	...
  601017:	00 76 04             	add    %dh,0x4(%rsi)
  60101a:	40 00 00             	add    %al,(%rax)
  60101d:	00 00                	add    %al,(%rax)
  60101f:	00 86 04 40 00 00    	add    %al,0x4004(%rsi)
  601025:	00 00                	add    %al,(%rax)
  601027:	00 96 04 40 00 00    	add    %dl,0x4004(%rsi)
  60102d:	00 00                	add    %al,(%rax)
  60102f:	00 a6 04 40 00 00    	add    %ah,0x4004(%rsi)
  601035:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000601038 <__data_start>:
	...

0000000000601040 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000601048 <__bss_start>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 53 55             	sub    %dl,0x55(%rbx)
   8:	53                   	push   %rbx
   9:	45 20 4c 69 6e       	and    %r9b,0x6e(%r9,%rbp,2)
   e:	75 78                	jne    88 <_init-0x4003b8>
  10:	29 20                	sub    %esp,(%rax)
  12:	34 2e                	xor    $0x2e,%al
  14:	38 2e                	cmp    %ch,(%rsi)
  16:	33 20                	xor    (%rax),%esp
  18:	32 30                	xor    (%rax),%dh
  1a:	31 34 30             	xor    %esi,(%rax,%rsi,1)
  1d:	36 32 37             	xor    %ss:(%rdi),%dh
  20:	20 5b 67             	and    %bl,0x67(%rbx)
  23:	63 63 2d             	movslq 0x2d(%rbx),%esp
  26:	34 5f                	xor    $0x5f,%al
  28:	38 2d 62 72 61 6e    	cmp    %ch,0x6e617262(%rip)        # 6e617290 <_end+0x6e016240>
  2e:	63 68 20             	movslq 0x20(%rax),%ebp
  31:	72 65                	jb     98 <_init-0x4003a8>
  33:	76 69                	jbe    9e <_init-0x4003a2>
  35:	73 69                	jae    a0 <_init-0x4003a0>
  37:	6f                   	outsl  %ds:(%rsi),(%dx)
  38:	6e                   	outsb  %ds:(%rsi),(%dx)
  39:	20 32                	and    %dh,(%rdx)
  3b:	31 32                	xor    %esi,(%rdx)
  3d:	30 36                	xor    %dh,(%rsi)
  3f:	34 5d                	xor    $0x5d,%al
	...

Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 00                	or     %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	b0 04                	mov    $0x4,%al
  12:	40 00 00             	add    %al,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 2a                	add    %ch,(%rdx)
	...
  2d:	00 00                	add    %al,(%rax)
  2f:	00 1c 00             	add    %bl,(%rax,%rax,1)
  32:	00 00                	add    %al,(%rax)
  34:	02 00                	add    (%rax),%al
  36:	75 00                	jne    38 <_init-0x400408>
  38:	00 00                	add    %al,(%rax)
  3a:	08 00                	or     %al,(%rax)
	...
  50:	3c 00                	cmp    $0x0,%al
  52:	00 00                	add    %al,(%rax)
  54:	02 00                	add    (%rax),%al
  56:	f3 00 00             	repz add %al,(%rax)
  59:	00 08                	add    %cl,(%rax)
  5b:	00 00                	add    %al,(%rax)
  5d:	00 00                	add    %al,(%rax)
  5f:	00 40 04             	add    %al,0x4(%rax)
  62:	40 00 00             	add    %al,(%rax)
  65:	00 00                	add    %al,(%rax)
  67:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 6d <_init-0x4003d3>
  6d:	00 00                	add    %al,(%rax)
  6f:	00 54 06 40          	add    %dl,0x40(%rsi,%rax,1)
  73:	00 00                	add    %al,(%rax)
  75:	00 00                	add    %al,(%rax)
  77:	00 04 00             	add    %al,(%rax,%rax,1)
	...
  8e:	00 00                	add    %al,(%rax)
  90:	2c 00                	sub    $0x0,%al
  92:	00 00                	add    %al,(%rax)
  94:	02 00                	add    (%rax),%al
  96:	5b                   	pop    %rbx
  97:	01 00                	add    %eax,(%rax)
  99:	00 08                	add    %cl,(%rax)
  9b:	00 00                	add    %al,(%rax)
  9d:	00 00                	add    %al,(%rax)
  9f:	00 e0                	add    %ah,%al
  a1:	05 40 00 00 00       	add    $0x40,%eax
  a6:	00 00                	add    %al,(%rax)
  a8:	72 00                	jb     aa <_init-0x400396>
	...
  be:	00 00                	add    %al,(%rax)
  c0:	3c 00                	cmp    $0x0,%al
  c2:	00 00                	add    %al,(%rax)
  c4:	02 00                	add    (%rax),%al
  c6:	b3 02                	mov    $0x2,%bl
  c8:	00 00                	add    %al,(%rax)
  ca:	08 00                	or     %al,(%rax)
  cc:	00 00                	add    %al,(%rax)
  ce:	00 00                	add    %al,(%rax)
  d0:	55                   	push   %rbp
  d1:	04 40                	add    $0x40,%al
  d3:	00 00                	add    %al,(%rax)
  d5:	00 00                	add    %al,(%rax)
  d7:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # dd <_init-0x400363>
  dd:	00 00                	add    %al,(%rax)
  df:	00 58 06             	add    %bl,0x6(%rax)
  e2:	40 00 00             	add    %al,(%rax)
  e5:	00 00                	add    %al,(%rax)
  e7:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # ed <_init-0x400353>
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	71 00                	jno    2 <_init-0x40043e>
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 01                	or     %al,(%rcx)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	b0 04                	mov    $0x4,%al
  12:	40 00 00             	add    %al,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 da                	add    %bl,%dl
  19:	04 40                	add    $0x40,%al
  1b:	00 00                	add    %al,(%rax)
  1d:	00 00                	add    %al,(%rax)
  1f:	00 2e                	add    %ch,(%rsi)
  21:	2e                   	cs
  22:	2f                   	(bad)  
  23:	73 79                	jae    9e <_init-0x4003a2>
  25:	73 64                	jae    8b <_init-0x4003b5>
  27:	65                   	gs
  28:	70 73                	jo     9d <_init-0x4003a3>
  2a:	2f                   	(bad)  
  2b:	78 38                	js     65 <_init-0x4003db>
  2d:	36                   	ss
  2e:	5f                   	pop    %rdi
  2f:	36                   	ss
  30:	34 2f                	xor    $0x2f,%al
  32:	73 74                	jae    a8 <_init-0x400398>
  34:	61                   	(bad)  
  35:	72 74                	jb     ab <_init-0x400395>
  37:	2e                   	cs
  38:	53                   	push   %rbx
  39:	00 2f                	add    %ch,(%rdi)
  3b:	68 6f 6d 65 2f       	pushq  $0x2f656d6f
  40:	61                   	(bad)  
  41:	62                   	(bad)  
  42:	75 69                	jne    ad <_init-0x400393>
  44:	6c                   	insb   (%dx),%es:(%rdi)
  45:	64                   	fs
  46:	2f                   	(bad)  
  47:	72 70                	jb     b9 <_init-0x400387>
  49:	6d                   	insl   (%dx),%es:(%rdi)
  4a:	62                   	(bad)  
  4b:	75 69                	jne    b6 <_init-0x40038a>
  4d:	6c                   	insb   (%dx),%es:(%rdi)
  4e:	64                   	fs
  4f:	2f                   	(bad)  
  50:	42 55                	rex.X push %rbp
  52:	49                   	rex.WB
  53:	4c                   	rex.WR
  54:	44 2f                	rex.R (bad) 
  56:	67 6c                	insb   (%dx),%es:(%edi)
  58:	69 62 63 2d 32 2e 31 	imul   $0x312e322d,0x63(%rdx),%esp
  5f:	39 2f                	cmp    %ebp,(%rdi)
  61:	63 73 75             	movslq 0x75(%rbx),%esi
  64:	00 47 4e             	add    %al,0x4e(%rdi)
  67:	55                   	push   %rbp
  68:	20 41 53             	and    %al,0x53(%rcx)
  6b:	20 32                	and    %dh,(%rdx)
  6d:	2e 32 34 2e          	xor    %cs:(%rsi,%rbp,1),%dh
  71:	30 00                	xor    %al,(%rax)
  73:	01 80 7a 00 00 00    	add    %eax,0x7a(%rax)
  79:	04 00                	add    $0x0,%al
  7b:	14 00                	adc    $0x0,%al
  7d:	00 00                	add    %al,(%rax)
  7f:	08 01                	or     %al,(%rcx)
  81:	12 00                	adc    (%rax),%al
  83:	00 00                	add    %al,(%rax)
  85:	01 68 02             	add    %ebp,0x2(%rax)
  88:	00 00                	add    %al,(%rax)
  8a:	38 01                	cmp    %al,(%rcx)
  8c:	00 00                	add    %al,(%rax)
  8e:	5d                   	pop    %rbp
  8f:	00 00                	add    %al,(%rax)
  91:	00 02                	add    %al,(%rdx)
  93:	01 08                	add    %ecx,(%rax)
  95:	05 01 00 00 02       	add    $0x2000001,%eax
  9a:	02 07                	add    (%rdi),%al
  9c:	25 01 00 00 02       	and    $0x2000001,%eax
  a1:	04 07                	add    $0x7,%al
  a3:	05 00 00 00 02       	add    $0x2000000,%eax
  a8:	08 07                	or     %al,(%rdi)
  aa:	00 00                	add    %al,(%rax)
  ac:	00 00                	add    %al,(%rax)
  ae:	02 01                	add    (%rcx),%al
  b0:	06                   	(bad)  
  b1:	07                   	(bad)  
  b2:	01 00                	add    %eax,(%rax)
  b4:	00 02                	add    %al,(%rdx)
  b6:	02 05 ec 00 00 00    	add    0xec(%rip),%al        # 1a8 <_init-0x400298>
  bc:	03 04 05 69 6e 74 00 	add    0x746e69(,%rax,1),%eax
  c3:	02 08                	add    (%rax),%cl
  c5:	05 13 01 00 00       	add    $0x113,%eax
  ca:	02 08                	add    (%rax),%cl
  cc:	07                   	(bad)  
  cd:	1c 01                	sbb    $0x1,%al
  cf:	00 00                	add    %al,(%rax)
  d1:	02 01                	add    (%rcx),%al
  d3:	06                   	(bad)  
  d4:	0e                   	(bad)  
  d5:	01 00                	add    %eax,(%rax)
  d7:	00 04 f6             	add    %al,(%rsi,%rsi,8)
  da:	00 00                	add    %al,(%rax)
  dc:	00 01                	add    %al,(%rcx)
  de:	18 78 00             	sbb    %bh,0x0(%rax)
  e1:	00 00                	add    %al,(%rax)
  e3:	09 03                	or     %eax,(%rbx)
  e5:	60                   	(bad)  
  e6:	06                   	(bad)  
  e7:	40 00 00             	add    %al,(%rax)
  ea:	00 00                	add    %al,(%rax)
  ec:	00 05 47 00 00 00    	add    %al,0x47(%rip)        # 139 <_init-0x400307>
  f2:	00 64 00 00          	add    %ah,0x0(%rax,%rax,1)
  f6:	00 02                	add    %al,(%rdx)
  f8:	00 52 00             	add    %dl,0x0(%rdx)
  fb:	00 00                	add    %al,(%rax)
  fd:	08 01                	or     %al,(%rcx)
  ff:	84 00                	test   %al,(%rax)
 101:	00 00                	add    %al,(%rax)
 103:	00 00                	add    %al,(%rax)
 105:	00 00                	add    %al,(%rax)
 107:	2e                   	cs
 108:	2e                   	cs
 109:	2f                   	(bad)  
 10a:	73 79                	jae    185 <_init-0x4002bb>
 10c:	73 64                	jae    172 <_init-0x4002ce>
 10e:	65                   	gs
 10f:	70 73                	jo     184 <_init-0x4002bc>
 111:	2f                   	(bad)  
 112:	78 38                	js     14c <_init-0x4002f4>
 114:	36                   	ss
 115:	5f                   	pop    %rdi
 116:	36                   	ss
 117:	34 2f                	xor    $0x2f,%al
 119:	63 72 74             	movslq 0x74(%rdx),%esi
 11c:	69 2e 53 00 2f 68    	imul   $0x682f0053,(%rsi),%ebp
 122:	6f                   	outsl  %ds:(%rsi),(%dx)
 123:	6d                   	insl   (%dx),%es:(%rdi)
 124:	65                   	gs
 125:	2f                   	(bad)  
 126:	61                   	(bad)  
 127:	62                   	(bad)  
 128:	75 69                	jne    193 <_init-0x4002ad>
 12a:	6c                   	insb   (%dx),%es:(%rdi)
 12b:	64                   	fs
 12c:	2f                   	(bad)  
 12d:	72 70                	jb     19f <_init-0x4002a1>
 12f:	6d                   	insl   (%dx),%es:(%rdi)
 130:	62                   	(bad)  
 131:	75 69                	jne    19c <_init-0x4002a4>
 133:	6c                   	insb   (%dx),%es:(%rdi)
 134:	64                   	fs
 135:	2f                   	(bad)  
 136:	42 55                	rex.X push %rbp
 138:	49                   	rex.WB
 139:	4c                   	rex.WR
 13a:	44 2f                	rex.R (bad) 
 13c:	67 6c                	insb   (%dx),%es:(%edi)
 13e:	69 62 63 2d 32 2e 31 	imul   $0x312e322d,0x63(%rdx),%esp
 145:	39 2f                	cmp    %ebp,(%rdi)
 147:	63 73 75             	movslq 0x75(%rbx),%esi
 14a:	00 47 4e             	add    %al,0x4e(%rdi)
 14d:	55                   	push   %rbp
 14e:	20 41 53             	and    %al,0x53(%rcx)
 151:	20 32                	and    %dh,(%rdx)
 153:	2e 32 34 2e          	xor    %cs:(%rsi,%rbp,1),%dh
 157:	30 00                	xor    %al,(%rax)
 159:	01 80 54 01 00 00    	add    %eax,0x154(%rax)
 15f:	04 00                	add    $0x0,%al
 161:	64 00 00             	add    %al,%fs:(%rax)
 164:	00 08                	add    %cl,(%rax)
 166:	01 74 01 00          	add    %esi,0x0(%rcx,%rax,1)
 16a:	00 01                	add    %al,(%rcx)
 16c:	64 02 00             	add    %fs:(%rax),%al
 16f:	00 38                	add    %bh,(%rax)
 171:	01 00                	add    %eax,(%rax)
 173:	00 e0                	add    %ah,%al
 175:	05 40 00 00 00       	add    $0x40,%eax
 17a:	00 00                	add    %al,(%rax)
 17c:	72 00                	jb     17e <_init-0x4002c2>
 17e:	00 00                	add    %al,(%rax)
 180:	00 00                	add    %al,(%rax)
 182:	00 00                	add    %al,(%rax)
 184:	e8 00 00 00 02       	callq  2000189 <_end+0x19ff139>
 189:	08 05 13 01 00 00    	or     %al,0x113(%rip)        # 2a2 <_init-0x40019e>
 18f:	03 63 01             	add    0x1(%rbx),%esp
 192:	00 00                	add    %al,(%rax)
 194:	02 d4                	add    %ah,%dl
 196:	3f                   	(bad)  
 197:	00 00                	add    %al,(%rax)
 199:	00 02                	add    %al,(%rdx)
 19b:	08 07                	or     %al,(%rdi)
 19d:	00 00                	add    %al,(%rax)
 19f:	00 00                	add    %al,(%rax)
 1a1:	04 04                	add    $0x4,%al
 1a3:	05 69 6e 74 00       	add    $0x746e69,%eax
 1a8:	05 54 02 00 00       	add    $0x254,%eax
 1ad:	01 43 e0             	add    %eax,-0x20(%rbx)
 1b0:	05 40 00 00 00       	add    $0x40,%eax
 1b5:	00 00                	add    %al,(%rax)
 1b7:	65 00 00             	add    %al,%gs:(%rax)
 1ba:	00 00                	add    %al,(%rax)
 1bc:	00 00                	add    %al,(%rax)
 1be:	00 01                	add    %al,(%rcx)
 1c0:	9c                   	pushfq 
 1c1:	e3 00                	jrcxz  1c3 <_init-0x40027d>
 1c3:	00 00                	add    %al,(%rax)
 1c5:	06                   	(bad)  
 1c6:	6f                   	outsl  %ds:(%rsi),(%dx)
 1c7:	01 00                	add    %eax,(%rax)
 1c9:	00 01                	add    %al,(%rcx)
 1cb:	43                   	rex.XB
 1cc:	46 00 00             	rex.RX add %r8b,(%rax)
 1cf:	00 00                	add    %al,(%rax)
 1d1:	00 00                	add    %al,(%rax)
 1d3:	00 06                	add    %al,(%rsi)
 1d5:	a8 02                	test   $0x2,%al
 1d7:	00 00                	add    %al,(%rax)
 1d9:	01 43 e3             	add    %eax,-0x1d(%rbx)
 1dc:	00 00                	add    %al,(%rax)
 1de:	00 4c 00 00          	add    %cl,0x0(%rax,%rax,1)
 1e2:	00 06                	add    %al,(%rsi)
 1e4:	6a 01                	pushq  $0x1
 1e6:	00 00                	add    %al,(%rax)
 1e8:	01 43 e3             	add    %eax,-0x1d(%rbx)
 1eb:	00 00                	add    %al,(%rax)
 1ed:	00 98 00 00 00 07    	add    %bl,0x7000000(%rax)
 1f3:	82                   	(bad)  
 1f4:	02 00                	add    (%rax),%al
 1f6:	00 01                	add    %al,(%rcx)
 1f8:	56                   	push   %rsi
 1f9:	f6 00 00             	testb  $0x0,(%rax)
 1fc:	00 08                	add    %cl,(%rax)
 1fe:	40 00 00             	add    %al,(%rax)
 201:	00 d5                	add    %dl,%ch
 203:	00 00                	add    %al,(%rax)
 205:	00 09                	add    %cl,(%rcx)
 207:	69 00 01 57 34 00    	imul   $0x345701,(%rax),%eax
 20d:	00 00                	add    %al,(%rax)
 20f:	e4 00                	in     $0x0,%al
 211:	00 00                	add    %al,(%rax)
 213:	0a 2d 06 40 00 00    	or     0x4006(%rip),%ch        # 421f <_init-0x3fc221>
 219:	00 00                	add    %al,(%rax)
 21b:	00 0b                	add    %cl,(%rbx)
 21d:	01 55 02             	add    %edx,0x2(%rbp)
 220:	7f 00                	jg     222 <_init-0x40021e>
 222:	0b 01                	or     (%rcx),%eax
 224:	54                   	push   %rsp
 225:	02 7e 00             	add    0x0(%rsi),%bh
 228:	0b 01                	or     (%rcx),%eax
 22a:	51                   	push   %rcx
 22b:	02 7d 00             	add    0x0(%rbp),%bh
 22e:	00 00                	add    %al,(%rax)
 230:	0c 13                	or     $0x13,%al
 232:	06                   	(bad)  
 233:	40 00 00             	add    %al,(%rax)
 236:	00 00                	add    %al,(%rax)
 238:	00 50 01             	add    %dl,0x1(%rax)
 23b:	00 00                	add    %al,(%rax)
 23d:	00 0d 08 e9 00 00    	add    %cl,0xe908(%rip)        # eb4b <_init-0x3f18f5>
 243:	00 0d 08 ef 00 00    	add    %cl,0xef08(%rip)        # f151 <_init-0x3f12ef>
 249:	00 02                	add    %al,(%rdx)
 24b:	01 06                	add    %eax,(%rsi)
 24d:	0e                   	(bad)  
 24e:	01 00                	add    %eax,(%rax)
 250:	00 0e                	add    %cl,(%rsi)
 252:	34 00                	xor    $0x0,%al
 254:	00 00                	add    %al,(%rax)
 256:	0f 98 02             	sets   (%rdx)
 259:	00 00                	add    %al,(%rax)
 25b:	01 5f 50             	add    %ebx,0x50(%rdi)
 25e:	06                   	(bad)  
 25f:	40 00 00             	add    %al,(%rax)
 262:	00 00                	add    %al,(%rax)
 264:	00 02                	add    %al,(%rdx)
 266:	00 00                	add    %al,(%rax)
 268:	00 00                	add    %al,(%rax)
 26a:	00 00                	add    %al,(%rax)
 26c:	00 01                	add    %al,(%rcx)
 26e:	9c                   	pushfq 
 26f:	10 1f                	adc    %bl,(%rdi)
 271:	01 00                	add    %eax,(%rax)
 273:	00 1f                	add    %bl,(%rdi)
 275:	01 00                	add    %eax,(%rax)
 277:	00 11                	add    %dl,(%rcx)
 279:	00 0d 08 25 01 00    	add    %cl,0x12508(%rip)        # 12787 <_init-0x3edcb9>
 27f:	00 12                	add    %dl,(%rdx)
 281:	3a 01                	cmp    (%rcx),%al
 283:	00 00                	add    %al,(%rax)
 285:	13 46 00             	adc    0x0(%rsi),%eax
 288:	00 00                	add    %al,(%rax)
 28a:	13 e3                	adc    %ebx,%esp
 28c:	00 00                	add    %al,(%rax)
 28e:	00 13                	add    %dl,(%rbx)
 290:	e3 00                	jrcxz  292 <_init-0x4001ae>
 292:	00 00                	add    %al,(%rax)
 294:	00 14 6f             	add    %dl,(%rdi,%rbp,2)
 297:	02 00                	add    (%rax),%al
 299:	00 01                	add    %al,(%rcx)
 29b:	2c 14                	sub    $0x14,%al
 29d:	01 00                	add    %eax,(%rax)
 29f:	00 14 87             	add    %dl,(%rdi,%rax,4)
 2a2:	02 00                	add    (%rax),%al
 2a4:	00 01                	add    %al,(%rcx)
 2a6:	2e                   	cs
 2a7:	14 01                	adc    $0x1,%al
 2a9:	00 00                	add    %al,(%rax)
 2ab:	15 5e 02 00 00       	adc    $0x25e,%eax
 2b0:	01 37                	add    %esi,(%rdi)
 2b2:	00 64 00 00          	add    %ah,0x0(%rax,%rax,1)
 2b6:	00 02                	add    %al,(%rdx)
 2b8:	00 71 01             	add    %dh,0x1(%rcx)
 2bb:	00 00                	add    %al,(%rax)
 2bd:	08 01                	or     %al,(%rcx)
 2bf:	86 01                	xchg   %al,(%rcx)
 2c1:	00 00                	add    %al,(%rax)
 2c3:	90                   	nop
 2c4:	00 00                	add    %al,(%rax)
 2c6:	00 2e                	add    %ch,(%rsi)
 2c8:	2e                   	cs
 2c9:	2f                   	(bad)  
 2ca:	73 79                	jae    345 <_init-0x4000fb>
 2cc:	73 64                	jae    332 <_init-0x40010e>
 2ce:	65                   	gs
 2cf:	70 73                	jo     344 <_init-0x4000fc>
 2d1:	2f                   	(bad)  
 2d2:	78 38                	js     30c <_init-0x400134>
 2d4:	36                   	ss
 2d5:	5f                   	pop    %rdi
 2d6:	36                   	ss
 2d7:	34 2f                	xor    $0x2f,%al
 2d9:	63 72 74             	movslq 0x74(%rdx),%esi
 2dc:	6e                   	outsb  %ds:(%rsi),(%dx)
 2dd:	2e                   	cs
 2de:	53                   	push   %rbx
 2df:	00 2f                	add    %ch,(%rdi)
 2e1:	68 6f 6d 65 2f       	pushq  $0x2f656d6f
 2e6:	61                   	(bad)  
 2e7:	62                   	(bad)  
 2e8:	75 69                	jne    353 <_init-0x4000ed>
 2ea:	6c                   	insb   (%dx),%es:(%rdi)
 2eb:	64                   	fs
 2ec:	2f                   	(bad)  
 2ed:	72 70                	jb     35f <_init-0x4000e1>
 2ef:	6d                   	insl   (%dx),%es:(%rdi)
 2f0:	62                   	(bad)  
 2f1:	75 69                	jne    35c <_init-0x4000e4>
 2f3:	6c                   	insb   (%dx),%es:(%rdi)
 2f4:	64                   	fs
 2f5:	2f                   	(bad)  
 2f6:	42 55                	rex.X push %rbp
 2f8:	49                   	rex.WB
 2f9:	4c                   	rex.WR
 2fa:	44 2f                	rex.R (bad) 
 2fc:	67 6c                	insb   (%dx),%es:(%edi)
 2fe:	69 62 63 2d 32 2e 31 	imul   $0x312e322d,0x63(%rdx),%esp
 305:	39 2f                	cmp    %ebp,(%rdi)
 307:	63 73 75             	movslq 0x75(%rbx),%esi
 30a:	00 47 4e             	add    %al,0x4e(%rdi)
 30d:	55                   	push   %rbp
 30e:	20 41 53             	and    %al,0x53(%rcx)
 311:	20 32                	and    %dh,(%rdx)
 313:	2e 32 34 2e          	xor    %cs:(%rsi,%rbp,1),%dh
 317:	30 00                	xor    %al,(%rax)
 319:	01                   	.byte 0x1
 31a:	80                   	.byte 0x80

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 11                	add    %edx,(%rcx)
   2:	00 10                	add    %dl,(%rax)
   4:	06                   	(bad)  
   5:	11 01                	adc    %eax,(%rcx)
   7:	12 01                	adc    (%rcx),%al
   9:	03 08                	add    (%rax),%ecx
   b:	1b 08                	sbb    (%rax),%ecx
   d:	25 08 13 05 00       	and    $0x51308,%eax
  12:	00 00                	add    %al,(%rax)
  14:	01 11                	add    %edx,(%rcx)
  16:	01 25 0e 13 0b 03    	add    %esp,0x30b130e(%rip)        # 30b132a <_end+0x2ab02da>
  1c:	0e                   	(bad)  
  1d:	1b 0e                	sbb    (%rsi),%ecx
  1f:	10 17                	adc    %dl,(%rdi)
  21:	00 00                	add    %al,(%rax)
  23:	02 24 00             	add    (%rax,%rax,1),%ah
  26:	0b 0b                	or     (%rbx),%ecx
  28:	3e 0b 03             	or     %ds:(%rbx),%eax
  2b:	0e                   	(bad)  
  2c:	00 00                	add    %al,(%rax)
  2e:	03 24 00             	add    (%rax,%rax,1),%esp
  31:	0b 0b                	or     (%rbx),%ecx
  33:	3e 0b 03             	or     %ds:(%rbx),%eax
  36:	08 00                	or     %al,(%rax)
  38:	00 04 34             	add    %al,(%rsp,%rsi,1)
  3b:	00 03                	add    %al,(%rbx)
  3d:	0e                   	(bad)  
  3e:	3a 0b                	cmp    (%rbx),%cl
  40:	3b 0b                	cmp    (%rbx),%ecx
  42:	49 13 3f             	adc    (%r15),%rdi
  45:	19 02                	sbb    %eax,(%rdx)
  47:	18 00                	sbb    %al,(%rax)
  49:	00 05 26 00 49 13    	add    %al,0x13490026(%rip)        # 13490075 <_end+0x12e8f025>
  4f:	00 00                	add    %al,(%rax)
  51:	00 01                	add    %al,(%rcx)
  53:	11 00                	adc    %eax,(%rax)
  55:	10 06                	adc    %al,(%rsi)
  57:	55                   	push   %rbp
  58:	06                   	(bad)  
  59:	03 08                	add    (%rax),%ecx
  5b:	1b 08                	sbb    (%rax),%ecx
  5d:	25 08 13 05 00       	and    $0x51308,%eax
  62:	00 00                	add    %al,(%rax)
  64:	01 11                	add    %edx,(%rcx)
  66:	01 25 0e 13 0b 03    	add    %esp,0x30b130e(%rip)        # 30b137a <_end+0x2ab032a>
  6c:	0e                   	(bad)  
  6d:	1b 0e                	sbb    (%rsi),%ecx
  6f:	11 01                	adc    %eax,(%rcx)
  71:	12 07                	adc    (%rdi),%al
  73:	10 17                	adc    %dl,(%rdi)
  75:	00 00                	add    %al,(%rax)
  77:	02 24 00             	add    (%rax,%rax,1),%ah
  7a:	0b 0b                	or     (%rbx),%ecx
  7c:	3e 0b 03             	or     %ds:(%rbx),%eax
  7f:	0e                   	(bad)  
  80:	00 00                	add    %al,(%rax)
  82:	03 16                	add    (%rsi),%edx
  84:	00 03                	add    %al,(%rbx)
  86:	0e                   	(bad)  
  87:	3a 0b                	cmp    (%rbx),%cl
  89:	3b 0b                	cmp    (%rbx),%ecx
  8b:	49 13 00             	adc    (%r8),%rax
  8e:	00 04 24             	add    %al,(%rsp)
  91:	00 0b                	add    %cl,(%rbx)
  93:	0b 3e                	or     (%rsi),%edi
  95:	0b 03                	or     (%rbx),%eax
  97:	08 00                	or     %al,(%rax)
  99:	00 05 2e 01 3f 19    	add    %al,0x193f012e(%rip)        # 193f01cd <_end+0x18def17d>
  9f:	03 0e                	add    (%rsi),%ecx
  a1:	3a 0b                	cmp    (%rbx),%cl
  a3:	3b 0b                	cmp    (%rbx),%ecx
  a5:	27                   	(bad)  
  a6:	19 11                	sbb    %edx,(%rcx)
  a8:	01 12                	add    %edx,(%rdx)
  aa:	07                   	(bad)  
  ab:	40 18 97 42 19 01 13 	sbb    %dl,0x13011942(%rdi)
  b2:	00 00                	add    %al,(%rax)
  b4:	06                   	(bad)  
  b5:	05 00 03 0e 3a       	add    $0x3a0e0300,%eax
  ba:	0b 3b                	or     (%rbx),%edi
  bc:	0b 49 13             	or     0x13(%rcx),%ecx
  bf:	02 17                	add    (%rdi),%dl
  c1:	00 00                	add    %al,(%rax)
  c3:	07                   	(bad)  
  c4:	34 00                	xor    $0x0,%al
  c6:	03 0e                	add    (%rsi),%ecx
  c8:	3a 0b                	cmp    (%rbx),%cl
  ca:	3b 0b                	cmp    (%rbx),%ecx
  cc:	49 13 00             	adc    (%r8),%rax
  cf:	00 08                	add    %cl,(%rax)
  d1:	0b 01                	or     (%rcx),%eax
  d3:	55                   	push   %rbp
  d4:	17                   	(bad)  
  d5:	01 13                	add    %edx,(%rbx)
  d7:	00 00                	add    %al,(%rax)
  d9:	09 34 00             	or     %esi,(%rax,%rax,1)
  dc:	03 08                	add    (%rax),%ecx
  de:	3a 0b                	cmp    (%rbx),%cl
  e0:	3b 0b                	cmp    (%rbx),%ecx
  e2:	49 13 02             	adc    (%r10),%rax
  e5:	17                   	(bad)  
  e6:	00 00                	add    %al,(%rax)
  e8:	0a 89 82 01 01 11    	or     0x11010182(%rcx),%cl
  ee:	01 00                	add    %eax,(%rax)
  f0:	00 0b                	add    %cl,(%rbx)
  f2:	8a 82 01 00 02 18    	mov    0x18020001(%rdx),%al
  f8:	91                   	xchg   %eax,%ecx
  f9:	42 18 00             	rex.X sbb %al,(%rax)
  fc:	00 0c 89             	add    %cl,(%rcx,%rcx,4)
  ff:	82                   	(bad)  
 100:	01 00                	add    %eax,(%rax)
 102:	11 01                	adc    %eax,(%rcx)
 104:	31 13                	xor    %edx,(%rbx)
 106:	00 00                	add    %al,(%rax)
 108:	0d 0f 00 0b 0b       	or     $0xb0b000f,%eax
 10d:	49 13 00             	adc    (%r8),%rax
 110:	00 0e                	add    %cl,(%rsi)
 112:	26 00 49 13          	add    %cl,%es:0x13(%rcx)
 116:	00 00                	add    %al,(%rax)
 118:	0f 2e 00             	ucomiss (%rax),%xmm0
 11b:	3f                   	(bad)  
 11c:	19 03                	sbb    %eax,(%rbx)
 11e:	0e                   	(bad)  
 11f:	3a 0b                	cmp    (%rbx),%cl
 121:	3b 0b                	cmp    (%rbx),%ecx
 123:	27                   	(bad)  
 124:	19 11                	sbb    %edx,(%rcx)
 126:	01 12                	add    %edx,(%rdx)
 128:	07                   	(bad)  
 129:	40 18 97 42 19 00 00 	sbb    %dl,0x1942(%rdi)
 130:	10 01                	adc    %al,(%rcx)
 132:	01 49 13             	add    %ecx,0x13(%rcx)
 135:	01 13                	add    %edx,(%rbx)
 137:	00 00                	add    %al,(%rax)
 139:	11 21                	adc    %esp,(%rcx)
 13b:	00 00                	add    %al,(%rax)
 13d:	00 12                	add    %dl,(%rdx)
 13f:	15 01 27 19 01       	adc    $0x1192701,%eax
 144:	13 00                	adc    (%rax),%eax
 146:	00 13                	add    %dl,(%rbx)
 148:	05 00 49 13 00       	add    $0x134900,%eax
 14d:	00 14 34             	add    %dl,(%rsp,%rsi,1)
 150:	00 03                	add    %al,(%rbx)
 152:	0e                   	(bad)  
 153:	3a 0b                	cmp    (%rbx),%cl
 155:	3b 0b                	cmp    (%rbx),%ecx
 157:	49 13 3f             	adc    (%r15),%rdi
 15a:	19 3c 19             	sbb    %edi,(%rcx,%rbx,1)
 15d:	00 00                	add    %al,(%rax)
 15f:	15 2e 00 3f 19       	adc    $0x193f002e,%eax
 164:	03 0e                	add    (%rsi),%ecx
 166:	3a 0b                	cmp    (%rbx),%cl
 168:	3b 0b                	cmp    (%rbx),%ecx
 16a:	27                   	(bad)  
 16b:	19 3c 19             	sbb    %edi,(%rcx,%rbx,1)
 16e:	00 00                	add    %al,(%rax)
 170:	00 01                	add    %al,(%rcx)
 172:	11 00                	adc    %eax,(%rax)
 174:	10 06                	adc    %al,(%rsi)
 176:	55                   	push   %rbp
 177:	06                   	(bad)  
 178:	03 08                	add    (%rax),%ecx
 17a:	1b 08                	sbb    (%rax),%ecx
 17c:	25 08 13 05 00       	and    $0x51308,%eax
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	59                   	pop    %rcx
   1:	00 00                	add    %al,(%rax)
   3:	00 02                	add    %al,(%rdx)
   5:	00 30                	add    %dh,(%rax)
   7:	00 00                	add    %al,(%rax)
   9:	00 01                	add    %al,(%rcx)
   b:	01 fb                	add    %edi,%ebx
   d:	0e                   	(bad)  
   e:	0d 00 01 01 01       	or     $0x1010100,%eax
  13:	01 00                	add    %eax,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	01 00                	add    %eax,(%rax)
  19:	00 01                	add    %al,(%rcx)
  1b:	2e                   	cs
  1c:	2e                   	cs
  1d:	2f                   	(bad)  
  1e:	73 79                	jae    99 <_init-0x4003a7>
  20:	73 64                	jae    86 <_init-0x4003ba>
  22:	65                   	gs
  23:	70 73                	jo     98 <_init-0x4003a8>
  25:	2f                   	(bad)  
  26:	78 38                	js     60 <_init-0x4003e0>
  28:	36                   	ss
  29:	5f                   	pop    %rdi
  2a:	36                   	ss
  2b:	34 00                	xor    $0x0,%al
  2d:	00 73 74             	add    %dh,0x74(%rbx)
  30:	61                   	(bad)  
  31:	72 74                	jb     a7 <_init-0x400399>
  33:	2e                   	cs
  34:	53                   	push   %rbx
  35:	00 01                	add    %al,(%rcx)
  37:	00 00                	add    %al,(%rax)
  39:	00 00                	add    %al,(%rax)
  3b:	09 02                	or     %eax,(%rdx)
  3d:	b0 04                	mov    $0x4,%al
  3f:	40 00 00             	add    %al,(%rax)
  42:	00 00                	add    %al,(%rax)
  44:	00 03                	add    %al,(%rbx)
  46:	c2 00 01             	retq   $0x100
  49:	03 10                	add    (%rax),%edx
  4b:	2e 42 23 3e          	rex.X and %cs:(%rsi),%edi
  4f:	4d 24 03             	rex.WRB and $0x3,%al
  52:	0e                   	(bad)  
  53:	20 75 76             	and    %dh,0x76(%rbp)
  56:	78 5b                	js     b3 <_init-0x40038d>
  58:	02 01                	add    (%rcx),%al
  5a:	00 01                	add    %al,(%rcx)
  5c:	01 23                	add    %esp,(%rbx)
  5e:	00 00                	add    %al,(%rax)
  60:	00 02                	add    %al,(%rdx)
  62:	00 1d 00 00 00 01    	add    %bl,0x1000000(%rip)        # 1000068 <_end+0x9ff018>
  68:	01 fb                	add    %edi,%ebx
  6a:	0e                   	(bad)  
  6b:	0d 00 01 01 01       	or     $0x1010100,%eax
  70:	01 00                	add    %eax,(%rax)
  72:	00 00                	add    %al,(%rax)
  74:	01 00                	add    %eax,(%rax)
  76:	00 01                	add    %al,(%rcx)
  78:	00 69 6e             	add    %ch,0x6e(%rcx)
  7b:	69 74 2e 63 00 00 00 	imul   $0x0,0x63(%rsi,%rbp,1),%esi
  82:	00 
  83:	00 60 00             	add    %ah,0x0(%rax)
  86:	00 00                	add    %al,(%rax)
  88:	02 00                	add    (%rax),%al
  8a:	2f                   	(bad)  
  8b:	00 00                	add    %al,(%rax)
  8d:	00 01                	add    %al,(%rcx)
  8f:	01 fb                	add    %edi,%ebx
  91:	0e                   	(bad)  
  92:	0d 00 01 01 01       	or     $0x1010100,%eax
  97:	01 00                	add    %eax,(%rax)
  99:	00 00                	add    %al,(%rax)
  9b:	01 00                	add    %eax,(%rax)
  9d:	00 01                	add    %al,(%rcx)
  9f:	2e                   	cs
  a0:	2e                   	cs
  a1:	2f                   	(bad)  
  a2:	73 79                	jae    11d <_init-0x400323>
  a4:	73 64                	jae    10a <_init-0x400336>
  a6:	65                   	gs
  a7:	70 73                	jo     11c <_init-0x400324>
  a9:	2f                   	(bad)  
  aa:	78 38                	js     e4 <_init-0x40035c>
  ac:	36                   	ss
  ad:	5f                   	pop    %rdi
  ae:	36                   	ss
  af:	34 00                	xor    $0x0,%al
  b1:	00 63 72             	add    %ah,0x72(%rbx)
  b4:	74 69                	je     11f <_init-0x400321>
  b6:	2e                   	cs
  b7:	53                   	push   %rbx
  b8:	00 01                	add    %al,(%rcx)
  ba:	00 00                	add    %al,(%rax)
  bc:	00 00                	add    %al,(%rax)
  be:	09 02                	or     %eax,(%rdx)
  c0:	40 04 40             	add    $0x40,%al
  c3:	00 00                	add    %al,(%rax)
  c5:	00 00                	add    %al,(%rax)
  c7:	00 03                	add    %al,(%rbx)
  c9:	3f                   	(bad)  
  ca:	01 4c 75 3d          	add    %ecx,0x3d(%rbp,%rsi,2)
  ce:	2f                   	(bad)  
  cf:	02 05 00 01 01 00    	add    0x10100(%rip),%al        # 101d5 <_init-0x3f026b>
  d5:	09 02                	or     %eax,(%rdx)
  d7:	54                   	push   %rsp
  d8:	06                   	(bad)  
  d9:	40 00 00             	add    %al,(%rax)
  dc:	00 00                	add    %al,(%rax)
  de:	00 03                	add    %al,(%rbx)
  e0:	cf                   	iret   
  e1:	00 01                	add    %al,(%rcx)
  e3:	02 04 00             	add    (%rax,%rax,1),%al
  e6:	01 01                	add    %eax,(%rcx)
  e8:	9a                   	(bad)  
  e9:	00 00                	add    %al,(%rax)
  eb:	00 02                	add    %al,(%rdx)
  ed:	00 5a 00             	add    %bl,0x0(%rdx)
  f0:	00 00                	add    %al,(%rax)
  f2:	01 01                	add    %eax,(%rcx)
  f4:	fb                   	sti    
  f5:	0e                   	(bad)  
  f6:	0d 00 01 01 01       	or     $0x1010100,%eax
  fb:	01 00                	add    %eax,(%rax)
  fd:	00 00                	add    %al,(%rax)
  ff:	01 00                	add    %eax,(%rax)
 101:	00 01                	add    %al,(%rcx)
 103:	2f                   	(bad)  
 104:	75 73                	jne    179 <_init-0x4002c7>
 106:	72 2f                	jb     137 <_init-0x400309>
 108:	6c                   	insb   (%dx),%es:(%rdi)
 109:	69 62 36 34 2f 67 63 	imul   $0x63672f34,0x36(%rdx),%esp
 110:	63 2f                	movslq (%rdi),%ebp
 112:	78 38                	js     14c <_init-0x4002f4>
 114:	36                   	ss
 115:	5f                   	pop    %rdi
 116:	36                   	ss
 117:	34 2d                	xor    $0x2d,%al
 119:	73 75                	jae    190 <_init-0x4002b0>
 11b:	73 65                	jae    182 <_init-0x4002be>
 11d:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 122:	78 2f                	js     153 <_init-0x4002ed>
 124:	34 2e                	xor    $0x2e,%al
 126:	38 2f                	cmp    %ch,(%rdi)
 128:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
 12f:	00 00                	add    %al,(%rax)
 131:	65                   	gs
 132:	6c                   	insb   (%dx),%es:(%rdi)
 133:	66 2d 69 6e          	sub    $0x6e69,%ax
 137:	69 74 2e 63 00 00 00 	imul   $0x0,0x63(%rsi,%rbp,1),%esi
 13e:	00 
 13f:	73 74                	jae    1b5 <_init-0x40028b>
 141:	64                   	fs
 142:	64                   	fs
 143:	65                   	gs
 144:	66                   	data16
 145:	2e                   	cs
 146:	68 00 01 00 00       	pushq  $0x100
 14b:	00 00                	add    %al,(%rax)
 14d:	09 02                	or     %eax,(%rdx)
 14f:	e0 05                	loopne 156 <_init-0x4002ea>
 151:	40 00 00             	add    %al,(%rax)
 154:	00 00                	add    %al,(%rax)
 156:	00 03                	add    %al,(%rbx)
 158:	c3                   	retq   
 159:	00 01                	add    %al,(%rcx)
 15b:	03 12                	add    (%rdx),%edx
 15d:	08 12                	or     %dl,(%rdx)
 15f:	03 6e 74             	add    0x74(%rsi),%ebp
 162:	03 12                	add    (%rdx),%edx
 164:	20 03                	and    %al,(%rbx)
 166:	6e                   	outsb  %ds:(%rsi),(%dx)
 167:	74 03                	je     16c <_init-0x4002d4>
 169:	12 20                	adc    (%rax),%ah
 16b:	3d 2d 03 6e 4a       	cmp    $0x4a6e032d,%eax
 170:	03 0f                	add    (%rdi),%ecx
 172:	4a 5c                	rex.WX pop %rsp
 174:	00 02                	add    %al,(%rdx)
 176:	04 02                	add    $0x2,%al
 178:	c9                   	leaveq 
 179:	00 02                	add    %al,(%rdx)
 17b:	04 02                	add    $0x2,%al
 17d:	c7                   	(bad)  
 17e:	92                   	xchg   %eax,%edx
 17f:	08 97 02 02 00 01    	or     %dl,0x1000202(%rdi)
 185:	01 5d 00             	add    %ebx,0x0(%rbp)
 188:	00 00                	add    %al,(%rax)
 18a:	02 00                	add    (%rax),%al
 18c:	2f                   	(bad)  
 18d:	00 00                	add    %al,(%rax)
 18f:	00 01                	add    %al,(%rcx)
 191:	01 fb                	add    %edi,%ebx
 193:	0e                   	(bad)  
 194:	0d 00 01 01 01       	or     $0x1010100,%eax
 199:	01 00                	add    %eax,(%rax)
 19b:	00 00                	add    %al,(%rax)
 19d:	01 00                	add    %eax,(%rax)
 19f:	00 01                	add    %al,(%rcx)
 1a1:	2e                   	cs
 1a2:	2e                   	cs
 1a3:	2f                   	(bad)  
 1a4:	73 79                	jae    21f <_init-0x400221>
 1a6:	73 64                	jae    20c <_init-0x400234>
 1a8:	65                   	gs
 1a9:	70 73                	jo     21e <_init-0x400222>
 1ab:	2f                   	(bad)  
 1ac:	78 38                	js     1e6 <_init-0x40025a>
 1ae:	36                   	ss
 1af:	5f                   	pop    %rdi
 1b0:	36                   	ss
 1b1:	34 00                	xor    $0x0,%al
 1b3:	00 63 72             	add    %ah,0x72(%rbx)
 1b6:	74 6e                	je     226 <_init-0x40021a>
 1b8:	2e                   	cs
 1b9:	53                   	push   %rbx
 1ba:	00 01                	add    %al,(%rcx)
 1bc:	00 00                	add    %al,(%rax)
 1be:	00 00                	add    %al,(%rax)
 1c0:	09 02                	or     %eax,(%rdx)
 1c2:	55                   	push   %rbp
 1c3:	04 40                	add    $0x40,%al
 1c5:	00 00                	add    %al,(%rax)
 1c7:	00 00                	add    %al,(%rax)
 1c9:	00 03                	add    %al,(%rbx)
 1cb:	27                   	(bad)  
 1cc:	01 4b 02             	add    %ecx,0x2(%rbx)
 1cf:	01 00                	add    %eax,(%rax)
 1d1:	01 01                	add    %eax,(%rcx)
 1d3:	00 09                	add    %cl,(%rcx)
 1d5:	02 58 06             	add    0x6(%rax),%bl
 1d8:	40 00 00             	add    %al,(%rax)
 1db:	00 00                	add    %al,(%rax)
 1dd:	00 03                	add    %al,(%rbx)
 1df:	2b 01                	sub    (%rcx),%eax
 1e1:	4b 02 01             	rex.WXB add (%r9),%al
 1e4:	00 01                	add    %al,(%rcx)
 1e6:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	6c                   	insb   (%dx),%es:(%rdi)
   1:	6f                   	outsl  %ds:(%rsi),(%dx)
   2:	6e                   	outsb  %ds:(%rsi),(%dx)
   3:	67 20 75 6e          	and    %dh,0x6e(%ebp)
   7:	73 69                	jae    72 <_init-0x4003ce>
   9:	67 6e                	outsb  %ds:(%esi),(%dx)
   b:	65 64 20 69 6e       	gs and %ch,%fs:%gs:0x6e(%rcx)
  10:	74 00                	je     12 <_init-0x40042e>
  12:	47                   	rex.RXB
  13:	4e 55                	rex.WRX push %rbp
  15:	20 43 20             	and    %al,0x20(%rbx)
  18:	34 2e                	xor    $0x2e,%al
  1a:	38 2e                	cmp    %ch,(%rsi)
  1c:	33 20                	xor    (%rax),%esp
  1e:	32 30                	xor    (%rax),%dh
  20:	31 34 30             	xor    %esi,(%rax,%rsi,1)
  23:	36 32 37             	xor    %ss:(%rdi),%dh
  26:	20 5b 67             	and    %bl,0x67(%rbx)
  29:	63 63 2d             	movslq 0x2d(%rbx),%esp
  2c:	34 5f                	xor    $0x5f,%al
  2e:	38 2d 62 72 61 6e    	cmp    %ch,0x6e617262(%rip)        # 6e617296 <_end+0x6e016246>
  34:	63 68 20             	movslq 0x20(%rax),%ebp
  37:	72 65                	jb     9e <_init-0x4003a2>
  39:	76 69                	jbe    a4 <_init-0x40039c>
  3b:	73 69                	jae    a6 <_init-0x40039a>
  3d:	6f                   	outsl  %ds:(%rsi),(%dx)
  3e:	6e                   	outsb  %ds:(%rsi),(%dx)
  3f:	20 32                	and    %dh,(%rdx)
  41:	31 32                	xor    %esi,(%rdx)
  43:	30 36                	xor    %dh,(%rsi)
  45:	34 5d                	xor    $0x5d,%al
  47:	20 2d 6d 74 75 6e    	and    %ch,0x6e75746d(%rip)        # 6e7574ba <_end+0x6e15646a>
  4d:	65                   	gs
  4e:	3d 67 65 6e 65       	cmp    $0x656e6567,%eax
  53:	72 69                	jb     be <_init-0x400382>
  55:	63 20                	movslq (%rax),%esp
  57:	2d 6d 61 72 63       	sub    $0x6372616d,%eax
  5c:	68 3d 78 38 36       	pushq  $0x3638783d
  61:	2d 36 34 20 2d       	sub    $0x2d203436,%eax
  66:	67 20 2d 4f 32 20 2d 	and    %ch,0x2d20324f(%eip)        # 2d2032bc <_end+0x2cc0226c>
  6d:	73 74                	jae    e3 <_init-0x40035d>
  6f:	64                   	fs
  70:	3d 67 6e 75 39       	cmp    $0x39756e67,%eax
  75:	39 20                	cmp    %esp,(%rax)
  77:	2d 66 67 6e 75       	sub    $0x756e6766,%eax
  7c:	38 39                	cmp    %bh,(%rcx)
  7e:	2d 69 6e 6c 69       	sub    $0x696c6e69,%eax
  83:	6e                   	outsb  %ds:(%rsi),(%dx)
  84:	65 20 2d 66 61 73 79 	and    %ch,%gs:0x79736166(%rip)        # 797361f1 <_end+0x791351a1>
  8b:	6e                   	outsb  %ds:(%rsi),(%dx)
  8c:	63 68 72             	movslq 0x72(%rax),%ebp
  8f:	6f                   	outsl  %ds:(%rsi),(%dx)
  90:	6e                   	outsb  %ds:(%rsi),(%dx)
  91:	6f                   	outsl  %ds:(%rsi),(%dx)
  92:	75 73                	jne    107 <_init-0x400339>
  94:	2d 75 6e 77 69       	sub    $0x69776e75,%eax
  99:	6e                   	outsb  %ds:(%rsi),(%dx)
  9a:	64                   	fs
  9b:	2d 74 61 62 6c       	sub    $0x6c626174,%eax
  a0:	65                   	gs
  a1:	73 20                	jae    c3 <_init-0x40037d>
  a3:	2d 66 6d 65 72       	sub    $0x72656d66,%eax
  a8:	67                   	addr32
  a9:	65                   	gs
  aa:	2d 61 6c 6c 2d       	sub    $0x2d6c6c61,%eax
  af:	63 6f 6e             	movslq 0x6e(%rdi),%ebp
  b2:	73 74                	jae    128 <_init-0x400318>
  b4:	61                   	(bad)  
  b5:	6e                   	outsb  %ds:(%rsi),(%dx)
  b6:	74 73                	je     12b <_init-0x400315>
  b8:	20 2d 66 6d 65 73    	and    %ch,0x73656d66(%rip)        # 73656e24 <_end+0x73055dd4>
  be:	73 61                	jae    121 <_init-0x40031f>
  c0:	67                   	addr32
  c1:	65                   	gs
  c2:	2d 6c 65 6e 67       	sub    $0x676e656c,%eax
  c7:	74 68                	je     131 <_init-0x40030f>
  c9:	3d 30 20 2d 66       	cmp    $0x662d2030,%eax
  ce:	72 6f                	jb     13f <_init-0x400301>
  d0:	75 6e                	jne    140 <_init-0x400300>
  d2:	64 69 6e 67 2d 6d 61 	imul   $0x74616d2d,%fs:0x67(%rsi),%ebp
  d9:	74 
  da:	68 20 2d 66 75       	pushq  $0x75662d20
  df:	6e                   	outsb  %ds:(%rsi),(%dx)
  e0:	77 69                	ja     14b <_init-0x4002f5>
  e2:	6e                   	outsb  %ds:(%rsi),(%dx)
  e3:	64                   	fs
  e4:	2d 74 61 62 6c       	sub    $0x6c626174,%eax
  e9:	65                   	gs
  ea:	73 00                	jae    ec <_init-0x400354>
  ec:	73 68                	jae    156 <_init-0x4002ea>
  ee:	6f                   	outsl  %ds:(%rsi),(%dx)
  ef:	72 74                	jb     165 <_init-0x4002db>
  f1:	20 69 6e             	and    %ch,0x6e(%rcx)
  f4:	74 00                	je     f6 <_init-0x40034a>
  f6:	5f                   	pop    %rdi
  f7:	49                   	rex.WB
  f8:	4f 5f                	rex.WRXB pop %r15
  fa:	73 74                	jae    170 <_init-0x4002d0>
  fc:	64 69 6e 5f 75 73 65 	imul   $0x64657375,%fs:0x5f(%rsi),%ebp
 103:	64 
 104:	00 75 6e             	add    %dh,0x6e(%rbp)
 107:	73 69                	jae    172 <_init-0x4002ce>
 109:	67 6e                	outsb  %ds:(%esi),(%dx)
 10b:	65 64 20 63 68       	gs and %ah,%fs:%gs:0x68(%rbx)
 110:	61                   	(bad)  
 111:	72 00                	jb     113 <_init-0x40032d>
 113:	6c                   	insb   (%dx),%es:(%rdi)
 114:	6f                   	outsl  %ds:(%rsi),(%dx)
 115:	6e                   	outsb  %ds:(%rsi),(%dx)
 116:	67 20 69 6e          	and    %ch,0x6e(%ecx)
 11a:	74 00                	je     11c <_init-0x400324>
 11c:	73 69                	jae    187 <_init-0x4002b9>
 11e:	7a 65                	jp     185 <_init-0x4002bb>
 120:	74 79                	je     19b <_init-0x4002a5>
 122:	70 65                	jo     189 <_init-0x4002b7>
 124:	00 73 68             	add    %dh,0x68(%rbx)
 127:	6f                   	outsl  %ds:(%rsi),(%dx)
 128:	72 74                	jb     19e <_init-0x4002a2>
 12a:	20 75 6e             	and    %dh,0x6e(%rbp)
 12d:	73 69                	jae    198 <_init-0x4002a8>
 12f:	67 6e                	outsb  %ds:(%esi),(%dx)
 131:	65 64 20 69 6e       	gs and %ch,%fs:%gs:0x6e(%rcx)
 136:	74 00                	je     138 <_init-0x400308>
 138:	2f                   	(bad)  
 139:	68 6f 6d 65 2f       	pushq  $0x2f656d6f
 13e:	61                   	(bad)  
 13f:	62                   	(bad)  
 140:	75 69                	jne    1ab <_init-0x400295>
 142:	6c                   	insb   (%dx),%es:(%rdi)
 143:	64                   	fs
 144:	2f                   	(bad)  
 145:	72 70                	jb     1b7 <_init-0x400289>
 147:	6d                   	insl   (%dx),%es:(%rdi)
 148:	62                   	(bad)  
 149:	75 69                	jne    1b4 <_init-0x40028c>
 14b:	6c                   	insb   (%dx),%es:(%rdi)
 14c:	64                   	fs
 14d:	2f                   	(bad)  
 14e:	42 55                	rex.X push %rbp
 150:	49                   	rex.WB
 151:	4c                   	rex.WR
 152:	44 2f                	rex.R (bad) 
 154:	67 6c                	insb   (%dx),%es:(%edi)
 156:	69 62 63 2d 32 2e 31 	imul   $0x312e322d,0x63(%rdx),%esp
 15d:	39 2f                	cmp    %ebp,(%rdi)
 15f:	63 73 75             	movslq 0x75(%rbx),%esi
 162:	00 73 69             	add    %dh,0x69(%rbx)
 165:	7a 65                	jp     1cc <_init-0x400274>
 167:	5f                   	pop    %rdi
 168:	74 00                	je     16a <_init-0x4002d6>
 16a:	65 6e                	outsb  %gs:(%rsi),(%dx)
 16c:	76 70                	jbe    1de <_init-0x400262>
 16e:	00 61 72             	add    %ah,0x72(%rcx)
 171:	67 63 00             	movslq (%eax),%eax
 174:	47                   	rex.RXB
 175:	4e 55                	rex.WRX push %rbp
 177:	20 43 20             	and    %al,0x20(%rbx)
 17a:	34 2e                	xor    $0x2e,%al
 17c:	38 2e                	cmp    %ch,(%rsi)
 17e:	33 20                	xor    (%rax),%esp
 180:	32 30                	xor    (%rax),%dh
 182:	31 34 30             	xor    %esi,(%rax,%rsi,1)
 185:	36 32 37             	xor    %ss:(%rdi),%dh
 188:	20 5b 67             	and    %bl,0x67(%rbx)
 18b:	63 63 2d             	movslq 0x2d(%rbx),%esp
 18e:	34 5f                	xor    $0x5f,%al
 190:	38 2d 62 72 61 6e    	cmp    %ch,0x6e617262(%rip)        # 6e6173f8 <_end+0x6e0163a8>
 196:	63 68 20             	movslq 0x20(%rax),%ebp
 199:	72 65                	jb     200 <_init-0x400240>
 19b:	76 69                	jbe    206 <_init-0x40023a>
 19d:	73 69                	jae    208 <_init-0x400238>
 19f:	6f                   	outsl  %ds:(%rsi),(%dx)
 1a0:	6e                   	outsb  %ds:(%rsi),(%dx)
 1a1:	20 32                	and    %dh,(%rdx)
 1a3:	31 32                	xor    %esi,(%rdx)
 1a5:	30 36                	xor    %dh,(%rsi)
 1a7:	34 5d                	xor    $0x5d,%al
 1a9:	20 2d 6d 74 75 6e    	and    %ch,0x6e75746d(%rip)        # 6e75761c <_end+0x6e1565cc>
 1af:	65                   	gs
 1b0:	3d 67 65 6e 65       	cmp    $0x656e6567,%eax
 1b5:	72 69                	jb     220 <_init-0x400220>
 1b7:	63 20                	movslq (%rax),%esp
 1b9:	2d 6d 61 72 63       	sub    $0x6372616d,%eax
 1be:	68 3d 78 38 36       	pushq  $0x3638783d
 1c3:	2d 36 34 20 2d       	sub    $0x2d203436,%eax
 1c8:	67 20 2d 4f 32 20 2d 	and    %ch,0x2d20324f(%eip)        # 2d20341e <_end+0x2cc023ce>
 1cf:	73 74                	jae    245 <_init-0x4001fb>
 1d1:	64                   	fs
 1d2:	3d 67 6e 75 39       	cmp    $0x39756e67,%eax
 1d7:	39 20                	cmp    %esp,(%rax)
 1d9:	2d 66 67 6e 75       	sub    $0x756e6766,%eax
 1de:	38 39                	cmp    %bh,(%rcx)
 1e0:	2d 69 6e 6c 69       	sub    $0x696c6e69,%eax
 1e5:	6e                   	outsb  %ds:(%rsi),(%dx)
 1e6:	65 20 2d 66 61 73 79 	and    %ch,%gs:0x79736166(%rip)        # 79736353 <_end+0x79135303>
 1ed:	6e                   	outsb  %ds:(%rsi),(%dx)
 1ee:	63 68 72             	movslq 0x72(%rax),%ebp
 1f1:	6f                   	outsl  %ds:(%rsi),(%dx)
 1f2:	6e                   	outsb  %ds:(%rsi),(%dx)
 1f3:	6f                   	outsl  %ds:(%rsi),(%dx)
 1f4:	75 73                	jne    269 <_init-0x4001d7>
 1f6:	2d 75 6e 77 69       	sub    $0x69776e75,%eax
 1fb:	6e                   	outsb  %ds:(%rsi),(%dx)
 1fc:	64                   	fs
 1fd:	2d 74 61 62 6c       	sub    $0x6c626174,%eax
 202:	65                   	gs
 203:	73 20                	jae    225 <_init-0x40021b>
 205:	2d 66 6d 65 72       	sub    $0x72656d66,%eax
 20a:	67                   	addr32
 20b:	65                   	gs
 20c:	2d 61 6c 6c 2d       	sub    $0x2d6c6c61,%eax
 211:	63 6f 6e             	movslq 0x6e(%rdi),%ebp
 214:	73 74                	jae    28a <_init-0x4001b6>
 216:	61                   	(bad)  
 217:	6e                   	outsb  %ds:(%rsi),(%dx)
 218:	74 73                	je     28d <_init-0x4001b3>
 21a:	20 2d 66 6d 65 73    	and    %ch,0x73656d66(%rip)        # 73656f86 <_end+0x73055f36>
 220:	73 61                	jae    283 <_init-0x4001bd>
 222:	67                   	addr32
 223:	65                   	gs
 224:	2d 6c 65 6e 67       	sub    $0x676e656c,%eax
 229:	74 68                	je     293 <_init-0x4001ad>
 22b:	3d 30 20 2d 66       	cmp    $0x662d2030,%eax
 230:	72 6f                	jb     2a1 <_init-0x40019f>
 232:	75 6e                	jne    2a2 <_init-0x40019e>
 234:	64 69 6e 67 2d 6d 61 	imul   $0x74616d2d,%fs:0x67(%rsi),%ebp
 23b:	74 
 23c:	68 20 2d 66 75       	pushq  $0x75662d20
 241:	6e                   	outsb  %ds:(%rsi),(%dx)
 242:	77 69                	ja     2ad <_init-0x400193>
 244:	6e                   	outsb  %ds:(%rsi),(%dx)
 245:	64                   	fs
 246:	2d 74 61 62 6c       	sub    $0x6c626174,%eax
 24b:	65                   	gs
 24c:	73 20                	jae    26e <_init-0x4001d2>
 24e:	2d 66 50 49 43       	sub    $0x43495066,%eax
 253:	00 5f 5f             	add    %bl,0x5f(%rdi)
 256:	6c                   	insb   (%dx),%es:(%rdi)
 257:	69 62 63 5f 63 73 75 	imul   $0x7573635f,0x63(%rdx),%esp
 25e:	5f                   	pop    %rdi
 25f:	69 6e 69 74 00 65 6c 	imul   $0x6c650074,0x69(%rsi),%ebp
 266:	66 2d 69 6e          	sub    $0x6e69,%ax
 26a:	69 74 2e 63 00 5f 5f 	imul   $0x695f5f00,0x63(%rsi,%rbp,1),%esi
 271:	69 
 272:	6e                   	outsb  %ds:(%rsi),(%dx)
 273:	69 74 5f 61 72 72 61 	imul   $0x79617272,0x61(%rdi,%rbx,2),%esi
 27a:	79 
 27b:	5f                   	pop    %rdi
 27c:	73 74                	jae    2f2 <_init-0x40014e>
 27e:	61                   	(bad)  
 27f:	72 74                	jb     2f5 <_init-0x40014b>
 281:	00 73 69             	add    %dh,0x69(%rbx)
 284:	7a 65                	jp     2eb <_init-0x400155>
 286:	00 5f 5f             	add    %bl,0x5f(%rdi)
 289:	69 6e 69 74 5f 61 72 	imul   $0x72615f74,0x69(%rsi),%ebp
 290:	72 61                	jb     2f3 <_init-0x40014d>
 292:	79 5f                	jns    2f3 <_init-0x40014d>
 294:	65 6e                	outsb  %gs:(%rsi),(%dx)
 296:	64 00 5f 5f          	add    %bl,%fs:0x5f(%rdi)
 29a:	6c                   	insb   (%dx),%es:(%rdi)
 29b:	69 62 63 5f 63 73 75 	imul   $0x7573635f,0x63(%rdx),%esp
 2a2:	5f                   	pop    %rdi
 2a3:	66 69 6e 69 00 61    	imul   $0x6100,0x69(%rsi),%bp
 2a9:	72 67                	jb     312 <_init-0x40012e>
 2ab:	76 00                	jbe    2ad <_init-0x400193>

Disassembly of section .debug_loc:

0000000000000000 <.debug_loc>:
	...
   8:	32 00                	xor    (%rax),%al
   a:	00 00                	add    %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	01 00                	add    %eax,(%rax)
  12:	55                   	push   %rbp
  13:	32 00                	xor    (%rax),%al
  15:	00 00                	add    %al,(%rax)
  17:	00 00                	add    %al,(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	64 00 00             	add    %al,%fs:(%rax)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 01                	add    %al,(%rcx)
  24:	00 5f 64             	add    %bl,0x64(%rdi)
  27:	00 00                	add    %al,(%rax)
  29:	00 00                	add    %al,(%rax)
  2b:	00 00                	add    %al,(%rax)
  2d:	00 65 00             	add    %ah,0x0(%rbp)
  30:	00 00                	add    %al,(%rax)
  32:	00 00                	add    %al,(%rax)
  34:	00 00                	add    %al,(%rax)
  36:	04 00                	add    $0x0,%al
  38:	f3 01 55 9f          	repz add %edx,-0x61(%rbp)
	...
  54:	32 00                	xor    (%rax),%al
  56:	00 00                	add    %al,(%rax)
  58:	00 00                	add    %al,(%rax)
  5a:	00 00                	add    %al,(%rax)
  5c:	01 00                	add    %eax,(%rax)
  5e:	54                   	push   %rsp
  5f:	32 00                	xor    (%rax),%al
  61:	00 00                	add    %al,(%rax)
  63:	00 00                	add    %al,(%rax)
  65:	00 00                	add    %al,(%rax)
  67:	62                   	(bad)  
  68:	00 00                	add    %al,(%rax)
  6a:	00 00                	add    %al,(%rax)
  6c:	00 00                	add    %al,(%rax)
  6e:	00 01                	add    %al,(%rcx)
  70:	00 5e 62             	add    %bl,0x62(%rsi)
  73:	00 00                	add    %al,(%rax)
  75:	00 00                	add    %al,(%rax)
  77:	00 00                	add    %al,(%rax)
  79:	00 65 00             	add    %ah,0x0(%rbp)
  7c:	00 00                	add    %al,(%rax)
  7e:	00 00                	add    %al,(%rax)
  80:	00 00                	add    %al,(%rax)
  82:	04 00                	add    $0x0,%al
  84:	f3 01 54 9f 00       	repz add %edx,0x0(%rdi,%rbx,4)
	...
  9d:	00 00                	add    %al,(%rax)
  9f:	00 32                	add    %dh,(%rdx)
  a1:	00 00                	add    %al,(%rax)
  a3:	00 00                	add    %al,(%rax)
  a5:	00 00                	add    %al,(%rax)
  a7:	00 01                	add    %al,(%rcx)
  a9:	00 51 32             	add    %dl,0x32(%rcx)
  ac:	00 00                	add    %al,(%rax)
  ae:	00 00                	add    %al,(%rax)
  b0:	00 00                	add    %al,(%rax)
  b2:	00 60 00             	add    %ah,0x0(%rax)
  b5:	00 00                	add    %al,(%rax)
  b7:	00 00                	add    %al,(%rax)
  b9:	00 00                	add    %al,(%rax)
  bb:	01 00                	add    %eax,(%rax)
  bd:	5d                   	pop    %rbp
  be:	60                   	(bad)  
  bf:	00 00                	add    %al,(%rax)
  c1:	00 00                	add    %al,(%rax)
  c3:	00 00                	add    %al,(%rax)
  c5:	00 65 00             	add    %ah,0x0(%rbp)
  c8:	00 00                	add    %al,(%rax)
  ca:	00 00                	add    %al,(%rax)
  cc:	00 00                	add    %al,(%rax)
  ce:	04 00                	add    $0x0,%al
  d0:	f3 01 51 9f          	repz add %edx,-0x61(%rcx)
	...
  e4:	33 00                	xor    (%rax),%eax
  e6:	00 00                	add    %al,(%rax)
  e8:	00 00                	add    %al,(%rax)
  ea:	00 00                	add    %al,(%rax)
  ec:	38 00                	cmp    %al,(%rax)
  ee:	00 00                	add    %al,(%rax)
  f0:	00 00                	add    %al,(%rax)
  f2:	00 00                	add    %al,(%rax)
  f4:	02 00                	add    (%rax),%al
  f6:	30 9f 38 00 00 00    	xor    %bl,0x38(%rdi)
  fc:	00 00                	add    %al,(%rax)
  fe:	00 00                	add    %al,(%rax)
 100:	56                   	push   %rsi
 101:	00 00                	add    %al,(%rax)
 103:	00 00                	add    %al,(%rax)
 105:	00 00                	add    %al,(%rax)
 107:	00 01                	add    %al,(%rcx)
 109:	00 53 00             	add    %dl,0x0(%rbx)
	...

Disassembly of section .debug_ranges:

0000000000000000 <.debug_ranges>:
   0:	ff                   	(bad)  
   1:	ff                   	(bad)  
   2:	ff                   	(bad)  
   3:	ff                   	(bad)  
   4:	ff                   	(bad)  
   5:	ff                   	(bad)  
   6:	ff                   	(bad)  
   7:	ff 00                	incl   (%rax)
   9:	00 00                	add    %al,(%rax)
   b:	00 00                	add    %al,(%rax)
   d:	00 00                	add    %al,(%rax)
   f:	00 40 04             	add    %al,0x4(%rax)
  12:	40 00 00             	add    %al,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 55 04             	add    %dl,0x4(%rbp)
  1a:	40 00 00             	add    %al,(%rax)
  1d:	00 00                	add    %al,(%rax)
  1f:	00 54 06 40          	add    %dl,0x40(%rsi,%rax,1)
  23:	00 00                	add    %al,(%rax)
  25:	00 00                	add    %al,(%rax)
  27:	00 58 06             	add    %bl,0x6(%rax)
  2a:	40 00 00             	add    %al,(%rax)
	...
  3d:	00 00                	add    %al,(%rax)
  3f:	00 11                	add    %dl,(%rcx)
  41:	00 00                	add    %al,(%rax)
  43:	00 00                	add    %al,(%rax)
  45:	00 00                	add    %al,(%rax)
  47:	00 18                	add    %bl,(%rax)
  49:	00 00                	add    %al,(%rax)
  4b:	00 00                	add    %al,(%rax)
  4d:	00 00                	add    %al,(%rax)
  4f:	00 19                	add    %bl,(%rcx)
  51:	00 00                	add    %al,(%rax)
  53:	00 00                	add    %al,(%rax)
  55:	00 00                	add    %al,(%rax)
  57:	00 20                	add    %ah,(%rax)
  59:	00 00                	add    %al,(%rax)
  5b:	00 00                	add    %al,(%rax)
  5d:	00 00                	add    %al,(%rax)
  5f:	00 21                	add    %ah,(%rcx)
  61:	00 00                	add    %al,(%rax)
  63:	00 00                	add    %al,(%rax)
  65:	00 00                	add    %al,(%rax)
  67:	00 2a                	add    %ch,(%rdx)
  69:	00 00                	add    %al,(%rax)
  6b:	00 00                	add    %al,(%rax)
  6d:	00 00                	add    %al,(%rax)
  6f:	00 33                	add    %dh,(%rbx)
  71:	00 00                	add    %al,(%rax)
  73:	00 00                	add    %al,(%rax)
  75:	00 00                	add    %al,(%rax)
  77:	00 56 00             	add    %dl,0x0(%rsi)
	...
  8e:	00 00                	add    %al,(%rax)
  90:	ff                   	(bad)  
  91:	ff                   	(bad)  
  92:	ff                   	(bad)  
  93:	ff                   	(bad)  
  94:	ff                   	(bad)  
  95:	ff                   	(bad)  
  96:	ff                   	(bad)  
  97:	ff 00                	incl   (%rax)
  99:	00 00                	add    %al,(%rax)
  9b:	00 00                	add    %al,(%rax)
  9d:	00 00                	add    %al,(%rax)
  9f:	00 55 04             	add    %dl,0x4(%rbp)
  a2:	40 00 00             	add    %al,(%rax)
  a5:	00 00                	add    %al,(%rax)
  a7:	00 5a 04             	add    %bl,0x4(%rdx)
  aa:	40 00 00             	add    %al,(%rax)
  ad:	00 00                	add    %al,(%rax)
  af:	00 58 06             	add    %bl,0x6(%rax)
  b2:	40 00 00             	add    %al,(%rax)
  b5:	00 00                	add    %al,(%rax)
  b7:	00 5d 06             	add    %bl,0x6(%rbp)
  ba:	40 00 00             	add    %al,(%rax)
	...
