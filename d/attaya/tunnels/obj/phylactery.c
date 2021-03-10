//Coded by Lujke

// This phylactery of health can be used as a cure for the disease carried
// by the devil mark of the barbarzu devils.

#include <std.h>
inherit OBJECT;
int uses;

void create() {
    ::create();
    set_name("phylactery");
    set_id( ({"phial","phylactery", "small phial", "liquid", 
              "phylactery of health", "ointment"}) );
    set_short("%^BOLD%^%^MAGENTA%^Phyl%^RESET%^%^MAGENTA%^a%^BOLD%^"
             +"%^MAGENTA%^ctery of %^YELLOW$%H%^RESET%^%^ORANGE%^ea"
             +"%^YELLOW%^lth%^RESET%^");
    set_obvious_short("%^ORANGE%^a small %^CYAN%^phial%^ORANGE%^ of"
                     +" %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld"
                     +"%^RESET%^%^ORANGE%^e%^YELLOW%^n%^RESET%^%^ORANGE%^"
                     +" liquid");
    set_weight(2);
    set_long("%^ORANGE%^A small phial filled with a beautiful,"
            +" %^YELLOW%^sh%^RESET%^%^ORANGE%^i%^YELLOW%^mm%^RESET%^"
            +"%^ORANGE%^e%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^ng"
            +" g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e"
            +"%^YELLOW%^n l%^RESET%^%^ORANGE%^i%^YELLOW%^q%^RESET%^"
            +"%^ORANGE%^ui%^YELLOW%^d%^RESET%^%^ORANGE%^. The phial is"
            +" carefully stoppered with a very strange looking soft"
            +" %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^ cork, presumably"
            +" to prevent any of the %^MAGENTA%^pr%^BOLD%^%^MAGENTA%^e"
            +"%^RESET%^%^MAGENTA%^c%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA"
            +"%^ous %^ORANGE%^l%^RESET%^%^ORANGE%^i%^YELLOW%^q%^RESET%^"
            +"%^ORANGE%^ui%^YELLOW%^d%^RESET%^%^ORANGE%^ being lost.");
    set_lore("You have heard of a certain mythical curealls that are"
           +" reputed even to be able to heal some diseases of an"
           +" %^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^rc%^BOLD%^%^GREEN%^a"
  +"%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^e%^RESET%^ or %^RED%^inf%^BOLD%^"
            +"%^RED%^e%^RESET%^%^RED%^rn%^BOLD%^%^RED%^a%^RESET%^%^RED%^l"
            +"%^RESET%^ nature. One such cureall, the legendary%^BOLD%^"
            +"%^MAGENTA%^Phyl%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^"
            +"ctery of %^YELLOW$%H%^RESET%^%^ORANGE%^ea%^YELLOW%^lth"
            +" %^RESET%^is rumoured to be a beautiful liquid,"
            +" %^YELLOW%^sh%^RESET%^%^ORANGE%^i%^YELLOW%^mm%^RESET%^"
            +"%^ORANGE%^e%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^ng"
            +" g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^ in colour.\n"
            +" Surely this could not be that legendary ointment, could"
            +" it?");
  set_property("lore",19);
  set_read("From the label on the phial, you determine that to use the"
          +" phylactery, you would need to %^YELLOW%^'apply ointment to"
          +" <person>'%^RESET%^");
  uses = 2 + random(5);
}

void init()
{
  ::init();
  add_action("apply_ointment", "apply");
}

int apply_ointment(string str)
{
  object targ, mark;
  string targname;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)||!interactive(ETO)){
    return 1;
  }
  if (uses<1){
    tell_object(ETO, "There's nothing left in the bottle!");
    return 1;
  }
  if ((int)ETO->query_class_level("cleric")<25
     && (int)ETO->query_nwp("healing")<17){
    tell_object(ETO, "You don't really have the healing knowledge to be"
                    +" able to use the ointment effectively");
    return 1;
  }
  sscanf(str, "ointment to %s", targname);
  if (!targname){
    tell_object(ETO, "Try 'apply ointment to <target>'");
    return 1;
  }
  targ = present(targname, EETO);
  if (!objectp(targ)||!interactive(targ)){
    tell_object(ETO, "You can only use the phylactery on a living"
                    +" creature!");
    return 1;
  }
  mark = present("devil mark", targ);
  if (!objectp(mark)
       ||!mark->query_worn()){
    tell_object(ETO, "You cannot determine anything wrong with " 
                    + targ->QCN + " that you think this phylactery will"
                    +" heal.");
    tell_object(targ, (string)ETO->QCN + " examines you but sighs and"
                   +" does nothing further.");
    tell_room(EETO, ETO->QCN + " examines " + targ->QCN + " but sighs and"
                   +" does nothing further.", targ, ETO);
    return 1;
  }
  tell_object(ETO, "You carefully apply the %^YELLOW%^sh%^RESET%^"
                  +"%^ORANGE%^i%^YELLOW%^mm%^RESET%^%^ORANGE%^e"
                  +"%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^ng"
                  +" g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^"
                  +"%^ORANGE%^e%^YELLOW%^n l%^RESET%^%^ORANGE%^i"
                  +"%^YELLOW%^q%^RESET%^%^ORANGE%^ui%^YELLOW%^d%^RESET%^"
                  +" to " + targ->QCN + "%^RESET%^ in the manner"
                  +" described on the label. Now you just have to hope it"
                  +" works!");
  tell_object(targ, (string)ETO->QCN + "examines you and carefully"
                  +" applies some of the"
                  +" %^YELLOW%^sh%^RESET%^%^ORANGE%^i%^YELLOW%^mm"
                  +"%^RESET%^%^ORANGE%^e%^YELLOW%^r%^RESET%^%^ORANGE%^i"
                  +"%^YELLOW%^ng g%^RESET%^%^ORANGE%^o%^YELLOW%^ld"
                  +"%^RESET%^%^ORANGE%^e%^YELLOW%^n l%^RESET%^%^ORANGE%^i"
                  +"%^YELLOW%^q%^RESET%^%^ORANGE%^ui%^YELLOW%^d%^RESET%^"
                  +" to you.");
  tell_room(EETO, (string)ETO->QCN + " examines " + (string)targ->QCN 
                  +" and "
                  +" carefully applies some of the %^YELLOW%^sh%^RESET%^"
                  +"%^ORANGE%^i%^YELLOW%^mm%^RESET%^%^ORANGE%^e"
                  +"%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^ng"
                  +" g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^"
                  +"%^ORANGE%^e%^YELLOW%^n l%^RESET%^%^ORANGE%^i"
                  +"%^YELLOW%^q%^RESET%^%^ORANGE%^ui%^YELLOW%^d%^RESET%^"
                  +" to " + (string)targ->QO, ({targ, ETO}));
  tell_object(targ, "%^CYAN%^A strange, %^BOLD%^%^CYAN%^shining"
                   +" a%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^r%^RESET%^"
                   +"%^CYAN%^a surrounds you for a moment and you feel"
                   +" the weight of %^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^i"
                   +"%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^ea%^BOLD%^"
                   +"%^GREEN%^s%^RESET%^%^GREEN%^e%^CYAN%^ lift from you,"
                   +" leaving you feeling more %^BOLD%^%^MAGENTA%^alive"
                   +" %^RESET%^%^CYAN%^than you can ever remember.");
  tell_room(EETO, "%^CYAN%^A strange, %^BOLD%^%^CYAN%^shining"
                   +" a%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^r%^RESET%^"
                   +"%^CYAN%^a surrounds " + targ->QCN + "%^RESET%^"
                   +"%^CYAN%^ for a moment. " + targ->QCN +"%^RESET%^"
                   +"%^CYAN%^ tenses very"
                   +" briefly before appearing to %^BOLD%^%^GREEN%^relax"
                   +" %^RESET%^%^CYAN%^completely, a broad smile"
                   +" spreading over " + targ->QP + " features", targ);
  mark->unwear();
  mark->remove();
  uses--;
  return 1;
}
