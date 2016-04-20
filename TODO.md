# TODO

- [ ] Résolution des adresses de tous les symboles indexés par le binaire (statiques ou dynamiques) Bastien
	- [ ] /proc/self/maps
	- [ ] man dlinfo
	- [ ] man `dl_iterate_phdr`
	- [ ] `link_map`
	- [ ] Look in given binary
	- [ ] Look in extern lib
		- [ ] Static
		- [ ] Dynamic
		- [ ] `LD_PRELOAD`
		- [ ] /etc/ld.so.preload
		- [ ] /etc/ld.so.cache
- [ ] Détection des opcodes d'appel de fonction (Florian)
	- [ ] Appel recursif
	- [ ] calls / syscalls / ret
	- [ ] jmp / jle / ...
	- [ ] Mod R/M - FF/2
- [ ] Affichage finale
