inherit "/std/Object";
void create(){
  ::create();
  set_name("blackened key");
  set_id(({"blackened key","key"}));
  set_short("%^BOLD%^%^BLACK%^blackened key%^RESET%^");
  set_long(
  "  This large heavy duty key looks like its been left in a pool of blood for to long and has started to rust in its embrace."
  );
  set_weight(5);
  set("value",10);
}
void save_me(string file) {return 1;}
