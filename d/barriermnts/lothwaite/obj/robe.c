inherit "/std/armour";

#define COLORS ({"%^BLUE%^navy","%^BOLD%^%^BLUE%^cobalt","%^CYAN%^azure","%^BOLD%^%^CYAN%^sky blue","%^GREEN%^olive green","%^BOLD%^%^GREEN%^pine green","%^RED%^maroon","%^BOLD%^%^RED%^red","%^ORANGE%^russet brown","%^YELLOW%^yellow","%^BOLD%^%^BLACK%^charcoal gray","gray","%^BOLD%^%^WHITE%^white"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
    set_name("robe");
    set_id(({"robe","armor"}));
    set_short("A "+COLOR+" robe%^RESET%^");
    set_long( 
       "This simple robe is made of thick wool dyed "+COLOR+"%^RESET%^.  "+
       "The wool contains a light embroidery done in metallic "+COLOR+""+
       "%^RESET%^, dressing it up a bit.  The robe falls in "+
       "pleats to the wearer's ankles and offers some amount "+
       "of protection."
    );
    set_weight(10);
    set_value(25);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_ac(1);
    set_size(3);
}
