inherit "/std/armour";

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

void create(){
  ::create();
  set_name("robe");
  set_id(({"robe","sprite robe","acorn's robe", 
"acorn's spirte robe"}));
  set_obvious_short("%^RESET%^a %^GREEN%^l%^ORANGE%^e%^GREEN%^"+
"af g%^ORANGE%^r%^RESET%^e%^GREEN%^en %^RESET%^robe");
  set_short("%^RESET%^%^ORANGE%^a%^GREEN%^c%^WHITE%^o%^ORANGE%^"+
"rn's %^GREEN%^s%^ORANGE%^p%^RESET%^r%^GREEN%^i%^ORANGE%^t"+
"%^GREEN%^e %^ORANGE%^r%^GREEN%^o%^RESET%^b%^ORANGE%^e%^RESET%^");
  set_long("%^GREEN%^This little garment is made out of oak "+
"leaves and moss.  Barely big enough to fit a small child, the "+
"leaves are arranged to fit over each other so that they don't "+
"reveal anything.  They are stitched together by sticky strands "+
"of glossy moss which gives the garment a little extra "+
"sparkle.  The sleeves of the robe are short, only coming to "+
"about the elbows where lacy pieces of moss edge give the "+
"garment a slightly feminine appearance.%^RESET%^\n");
  set_weight(10);
  set_value(20);
  set_type("clothing");
  set_limbs(({"torso"}));
  set_ac(1);
}
