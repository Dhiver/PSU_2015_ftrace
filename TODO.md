# TODO

- [ ] Resolve names via adresses of all symboles in the binary (static and dynamic) Bastien
	- [x] Static
	- [/] Dynamic

- [ ] Detect functions calls (Florian)
	- [X] Main recursive loop
	- [X] calls / syscalls / ret
	- [x] Mod R/M - FF/2
	- [x] Check long macros
	- [x] Set be_the_parent_rec norm compliant
	- [ ] Watch given address to get_name_from_addr()

- [ ] Final printing
	- [x] Hide child output printing
	- [ ] Finalize (norm / valgrind / segv...)
		- [x] No -g in Makefile
		- [x] Norm
		- [x] Valgrind
		- [ ] Segv
		- [ ] Check for return cascade

