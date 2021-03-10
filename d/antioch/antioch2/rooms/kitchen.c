#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("The Royal Kitchen");
	set_long(
	"This is the extravagent kitchen of the Antioch palace. It is here where"+
	" the great chefs prepare the meals for the balls and banquets. The room"+
	" is large with many ovens, stoves, and counters. Bowls and cooking"+
	" utensils of all sorts are found in the cupboards, used for creating"+
	" normal dishes to any foreign delicacy a visiting ambassador might wish."+
	" The kitchen is currently lightly staffed, and there is always something"+
	" cooking here in case the palace residents should get hungry. There is"+
	" some sort of stew simmering in a large pot on one of the stoves."+
	" Freshly baked bread is covered by a towel on the counter to keep it"+
	" warm, and there is more baking in the oven. There are a few piping hot"+
	" pies of different varieties that have been set out to cool. Sliced"+
	" fruits and chopped vegetables are laid out on platters, along with"+
	" slices of bread and cheese. The kitchen has been cleverly designed to"+
	" allow for maximum capacity, with an island of stoves and ovens in the"+
	" center and counters and sinks around the edges. On the eastern side"+
	" of the room there is even a large fire pit for smoking meat, along with"+
	" a vent that releases all the smoke outside, instead of choking the room"+
	" with it. This is a very nice kitchen."
	);
	set_smell("default","You smell all sorts of delicious foods here.");
	set_listen("default","The stew slowly simmers on the stove.");
	set_items(([
	({"counter","counters"}) : "There are clean counter tops spanning most"+
	" of the kitchen. Some freshly baked bread is on one side, next to hot"+
	" pies, and plates of chopped fruits and vegetables, along with platters"+
	" of bread, meats, and cheeses.",
	({"oven","ovens","stove","stoves"}) : "Large brick ovens take up the"+
	" center space of the room. On top of each is either a spit, metal grill,"+
	" or flat metal surface that serves as a stove. The spits are best for"+
	" roasting meat on, giving it a delicious flavor. The metal grill with"+
	" a small fire beneath allows for quick cooking. The surface of flat"+
	" metal is a slightly newer invetion, kept warm by the heated oven beneath"+
	" it, it is where the stew pots are placed to allow them to keep warm.",
	({"pot","pots","kettle","kettles","utensils","bowls","dishes","cupboards"}) : "All"+
	" sorts of cooking utensils can be found around the room. Bowls and dishes"+
	" are kept in the cupboards, many pots and kettles are simmering on the"+
	" stoves, and the cooking utensils are kept in drawers around the room.",
	({"plate","plates","platters"}) : "Platters of food are laid out on the"+
	" counter for the palace staff. There are plates of sliced fruits and"+
	" vegetables, along with platters of thinly cut cheeses, meats, and breads.",
	({"bread","fresh bread"}) : "Some freshly baked bread is sitting on the"+
	" counter, covered by a towel to keep it nice and hot. With a bit of"+
	" butter melted onto it, it's a great snack.",
	({"pie","pies","hot pies","piping hot pies"}) : "Several delicious"+
	" smelling pies have been left out on the counter to cool. You can see"+
	" the steam rising from them. There are a couple varieties, ranging"+
	" from apple to strawberry, to blackberry. They look quite good.",
	({"meat","meats","cheese","cheeses","sliced meats","sliced bread","sliced cheese","sliced meat","sliced cheeses"}) : "A"+
	" plate of thinly sliced meats, breads, and cheeses has been left out for"+
	" the palace staff to snack on.",
	({"fruit","fruits","sliced fruits","vegetables","chopped vegetables"}) : "A"+
	" plate of sliced fruits and chopped vegetables has been beautifully"+
	" arranged. The fruits don't have a spot on them, and the vegetables"+
	" look fresh. Both appear to have been chilled for a little while.",
	"floor" : "The floor here is made out of some black stone that is"+
	" supposed to stay cool. It will help to keep any fires from spreading,"+
	" as well as keep the kitchen cooler when the ovens are on. It appears"+
	" quite spotless.",
	"ceiling" : "The ceiling is rather unremarkable. There are a few soot"+
	" stains on it from the stoves, but it looks as though it is cleaned"+
	" quite regularly.",
	({"sink","sinks"}) : "There are several large sinks around the room. They"+
	" are of the best magical quality. You have only to turn the knobs for"+
	" hot or cold water to come splashing out.",
	"stew" : "There are a couple large pots of stew simmering on the stoves.",
	"fire pit" : "On the eastern side of the room is a large fire pit with"+
	" a spit on it. It is used for roasting the larger animals, such as pig"+
	" or wild turkey. There is a vent next to the fire pit that sucks the"+
	" smoke out of the room, keeping the air in the kitchen clean.",
	"vent" : "A large vent on the eastern wall allows for the smoke to escape"+
	" outside instead of filling up the room.",
	]));
	set_exits(([
	"south" : ROOMS+"pal3",
	]));
	set_door("kitchen door",ROOMS+"pal3","south",0);
}

void reset()
{
   ::reset();
   if(!present("vardot")) {
      new(MONS+"chef")->move(TO);
   }
   return;
}
