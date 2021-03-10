object npcpresent(string id, object ob){
   object blah;
   return (blah = present(id,ob) && !userp(blah));
}
