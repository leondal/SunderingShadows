void destall(object ob){
    object *inven;
    
	int i,j;
    if(!objectp(ob)) return;

    inven = deep_inventory(ob);
    j = sizeof(inven);
    for(i=0;i<j;i++){
       if(!objectp(inven[i])) continue;
        inven[i]->remove();
     }

     if(objectp(ob)) ob->remove();
}
