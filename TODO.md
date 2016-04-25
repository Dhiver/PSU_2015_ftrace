# TODO

- [ ] Resolve names via adresses of all symboles in the binary (static and dynamic) Bastien
	- [/] Check for correct binary at all steps
	- [ ] Get Ehdr
	- [ ] Get Shdr
	- [ ] Static symbols
		- [ ] Get SHT_SYMTAB addr
		- [ ] Get SHT_SYMTAB end addr
		- [ ] Get SHT_SYMTAB corresponding strtab
		- [ ] Go to next static symbol
		- [ ] Know if symbol is a static function
	- [ ] Dynamic symbols
		- [ ] Get SHT_DYNSYM addr
		- [ ] Get SHT_DYNSYM end addr
		- [ ] Get SHT_DYNSYM corresponding strtab
		- [ ] Go to next dynamic symbol
		- [ ] Know if symbol is a dynamic function
	- [ ] At each break, see if addr in static or dynamic
	- [ ] print symbol name, else `func_0x8765FDE0@a.out`

- [ ] Detect functions calls (Florian)
	- [ ] Main recursive loop
	- [ ] calls / syscalls / ret
	- [ ] jmp / jle / ...
	- [ ] Mod R/M - FF/2
- [ ] Final printing

## Ressources

### Bastien

- [ ] /proc/self/maps
- [ ] man dlinfo
- [ ] man dladd
- [ ] man `dl_iterate_phdr`
- [ ] `link_map`
- [ ] Look in given binary
- [ ] Look in extern lib
	- [ ] Static
	- [ ] Dynamic
	- [ ] `LD_PRELOAD`
	- [ ] /etc/ld.so.preload
	- [ ] /etc/ld.so.cache
