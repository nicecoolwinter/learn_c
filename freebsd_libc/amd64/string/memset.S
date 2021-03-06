/*
 * Written by J.T. Conklin <jtc@NetBSD.org>.
 * Public domain.
 * Adapted for NetBSD/x86_64 by Frank van der Linden <fvdl@wasabisystems.com>
 */

#include <machine/asm.h>
__FBSDID("$FreeBSD: src/lib/libc/amd64/string/memset.S,v 1.1 2005/04/07 03:56:03 alc Exp $");

#if 0
	RCSID("$NetBSD: memset.S,v 1.3 2004/02/26 20:50:06 drochner Exp $")
#endif

ENTRY(memset)
	movq	%rsi,%rax
	andq	$0xff,%rax
	movq	%rdx,%rcx
	movq	%rdi,%r11

	cld				/* set fill direction forward */

	/*
	 * if the string is too short, it's really not worth the overhead
	 * of aligning to word boundries, etc.  So we jump to a plain
	 * unaligned set.
	 */
	cmpq	$0x0f,%rcx
	jle	L1

	movb	%al,%ah			/* copy char to all bytes in word */
	movl	%eax,%edx
	sall	$16,%eax
	orl	%edx,%eax

	movl	%eax,%edx
	salq	$32,%rax
	orq	%rdx,%rax

	movq	%rdi,%rdx		/* compute misalignment */
	negq	%rdx
	andq	$7,%rdx
	movq	%rcx,%r8
	subq	%rdx,%r8

	movq	%rdx,%rcx		/* set until word aligned */
	rep
	stosb

	movq	%r8,%rcx
	shrq	$3,%rcx			/* set by words */
	rep
	stosq

	movq	%r8,%rcx		/* set remainder by bytes */
	andq	$7,%rcx
L1:	rep
	stosb
	movq	%r11,%rax

	ret
