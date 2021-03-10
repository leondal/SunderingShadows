inherit "/std/Object";

void create(){
   ::create();
   set_name("gnomish extractor");
   set_id(({"extractor","gnomish extractor","tool","gnomish tool","gnomish extractor999"}));
   set_short("%^RED%^a gnomish extractor%^RESET%^");
   set_long("This unusual tool consists of several moving "+
      "pieces.  There is a small light powered by an "+
      "unknown source set just above a tiny hammer and "+
      "chisel.  All the parts are connected to swivels and "+
      "springs, making a complex tool that could only be "+
      "of gnomish design.  It looks as if it were made for "+
      "one purpose only.");
   set_lore("This tool was made by the gnome Rosinden to aid "+
      "her in the search for faerzress.  Any other attempt to "+
      "make use of it would likely be fruitless.");
   set_weight(1);
   set_value(0);
}