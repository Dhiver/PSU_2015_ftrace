# TODO

- [ ] Resolve names via adresses of all symboles in the binary (static and dynamic) Bastien
	- [ ] Dynamic
		- [ ] Section de type SHT_REL
		- [ ] Elf64_Rel
		- [ ] r_info

- [ ] Detect functions calls (Florian)
	- [X] Main recursive loop
	- [X] calls / syscalls / ret
	- [ ] jmp / jle / ...
	- [ ] Mod R/M - FF/2

- [ ] Final printing
	- [ ] Hide child output printing
	- [ ] Finalize

### Bastien

- [ ] /proc/self/maps
- [ ] man dlinfo
- [ ] man dladdr
- [ ] man `dl_iterate_phdr`
- [ ] `link_map`
- [ ] Look in given binary
- [ ] Look in extern lib
	- [ ] Static
	- [ ] Dynamic
	- [ ] `LD_PRELOAD`
	- [ ] /etc/ld.so.preload
	- [ ] /etc/ld.so.cache
