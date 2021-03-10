int realmso(object ob){
    string whom;
     if(!objectp(ob)) return 0;
               if(sscanf(geteuid(ob),"%sobj",whom) > 0){
		return 1;
	}
	return 0;
}
