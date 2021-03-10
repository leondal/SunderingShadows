inherit "/std/Object";

void create(){
   ::create();
   set_name("faerzress sample");
   set_id(({"rock","faerzress","sample","faerzress sample"}));
   set_short("a small sample of faerzress");
   set_long("Encased in a shell of ordinary stone are veins "+
      "of faintly glowing %^MAGENTA%^purple crystal%^RESET%^.  "+
      "This sample is only the size of a halfling's fist, "+
      "but it looks like there are pieces of faerzress "+
      "that could be pulled out, if you knew what you "+
      "were doing.");
   set_lore("This rock houses a good sample of faerzress, "+
      "a strange substance found in the underdark and named "+
      "by the drow.  It is often used in dark experiments "+
      "creating unnatural beings.  However, in such small "+
      "amounts, it likely won't have any unusual side "+
      "effects...you think.");
   set_weight(1);
   set_value(25);
}