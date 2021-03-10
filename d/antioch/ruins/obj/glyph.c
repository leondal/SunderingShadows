#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("glyph");
   set_short("A bloodstone");
   set_id(({"glyph","stone","bloodstone","bloodstone glyph"}));
   set_long("%^GREEN%^This is a bloodstone that has been carved into"+
   " a hexagonal shape. It is a dark green in color and is flecked"+
   " with red, legends say that it is supposed to have healing"+
   " properties and it is often used in magic. In the center of the"+
   " stone a perfect glyph is deeply carved and has been stained a"+
   " dark red.");
	set_lore("You examine the glyph carefully and pull up"+
      	" some long forgotten memories of ancient magical languages,"+
      	" realizing that this glyph is similar to very old derivatives"+
      	" of some of the most ancient ones. You believe that it is a"+
      	" glyph of warding. Or it might be a glyph of travel and safe"+
      	" passage. It's hard to determine since they are both similar"+
      	" and this one doesn't quite match any you've seen before.");
	set_property("lore",27);
   set_weight(5);
   set_value(1000);
   set_property("brazier sacrifice",1);
}

void init()
{
   ::init();
   add_action("read","read");
}

void read(string str)
{
   if(str == "glyph" || str == "stone" || str == "bloodstone") {
      if(!TP->is_class("mage")) {
         tell_object(TP,"Not being a mage you don't really know what"+
         " the magic symbol is.");
         tell_room(ETP,""+TPQCN+" stares at the glyph with a puzzled"+
         " expression.",TP);
         return 1;
      }
      else if(TP->query_stats("intelligence") < 18) {
         tell_object(TP,"Despite your extensive study in the arcane"+
         " field, you do not know what this glyph means.");
         tell_room(ETP,""+TPQCN+" examines the glyph for a moment.",TP);
         return 1;
      }
      tell_object(TP,"You examine the glyph carefully and pull up"+
      " some long forgotten memories of ancient magical languages,"+
      " realizing that this glyph is similar to very old derivatives"+
      " of some of the most ancient ones. You believe that it is a"+
      " glyph of warding. Or it might be a glyph of travel and safe"+
      " passage. It's hard to determine since they are both similar"+
      " and this one doesn't quite match any you've seen before.");
      tell_room(ETP,""+TPQCN+" carefully examines the glyph.",TP);
      return 1;
   }
}
 