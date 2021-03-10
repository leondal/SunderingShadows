inherit "/std/Object";
void create(){
  ::create();
  set_name("rusted key");
  set_id(({"rusted key","key","tomb key"}));
  set_short("%^RED%^rusted key%^RESET%^");
  set_long(
  "  This large heavy duty key looks like its been left in a pool of blood for to long and has started to rust in its embrace."
  );
  set_weight(5);
  set("value",10);
}
void save_me(string file) {return 1;}
