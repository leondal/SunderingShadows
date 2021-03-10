#include <std.h>
inherit OBJECT;

void create(){
  ::create();
  set_weight(99999);
  set_value(0);
  set_id(({ "sign","signpost","new sign","new signpost" }));
  set_short("%^RESET%^%^ORANGE%^A new signpost%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^The sign is new and freshly painted with "
"many words:\n\n"
"%^BOLD%^%^WHITE%^The Duke of Tonovi has taken note of threats issued by "
"unnamed sources upon the city and its denizens and will not tolerate "
"such threats to be made. Therefore, let it be known that:\n\n"
"%^BOLD%^%^WHITE%^-You are hereby officially notified that the roadways "
"between the Toll Booth and the crossroads north of Daggerdale, along "
"with the roads that lead to the City of Tonovi are under the purview of "
"the City of Tonovi and that travel upon them constitutes your "
"understanding and agreement to be held to account under the laws of "
"Tonovi.\n\n"
"%^BOLD%^%^WHITE%^-Further, the guards that patrol these roads are in "
"employment by the City of Tonovi and as such, act under the law of the "
"City of Tonovi and the Duke's order. Their duty is to patrol and "
"maintain the safety of travel along the roadways.\n\n"
"%^BOLD%^%^WHITE%^-Any aggression taken against these guards or any "
"citizens of the Great City of Tonovi will be met with force and be "
"considered treasonous.\n\n"
"%^BOLD%^%^WHITE%^-Those found guilty of such acts of aggression and/or "
"treason will result in fines and bounties placed upon their heads with "
"the eventual capture resulting in immediate public execution.\n\n"
"%^BOLD%^%^WHITE%^Signed under the seal of the Government of Tonovi.");
}
