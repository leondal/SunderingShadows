#include <std.h>
#include <move.h>
inherit DAEMON;

#define VALID_TYPES ({"weaponsmith","armorsmith","tailor","jeweller","woodworker","leatherworker","object"})
int help();

int cmd_item(string str){
   string file,name,type;
   object item;

   if(!str) return notify_fail("Usage: item <name>");
   if(sscanf(str, "-f %s -n %s -t %s",file, name, type) != 3) return help();
   if(member_array(type,VALID_TYPES) == -1) return help();
   if(file == "delete") return notify_fail("The file name 'delete' is reserved, please choose another.\n");
   file = "/d/avatars/"+TP->query_name()+"/"+file+".c";
   if(file_exists(file))
     return notify_fail("That file exists already, please choose another name, or first delete the file.\n");

   item = new ("/cmds/avatar/item.c");
   item->set_object_type(type);
   item->set_file_name(file);
   item->set_name(name);
   item->move(TP);
   return 1;

}

int help(){
   write(
@OLI
    Usage: item -f <filename> -n <item name> -t <type>

    The item command is the avatar command to make items. 
It is more complex than previous commands. This command 
will write out an actual file of code for the item being 
created. The parameters are as follows.
    -f <filename> where file name is the name of the file 
       to be saved as.  This should be 1 word.
    -n <item name> this is the name of the item.
    -t <type> this is ths type of item you are creating. 
       Available are weaponsmith, armorsmith, tailor, 
       jeweller, woodworker, leatherworker, and object.
OLI
       );
   write("    Note: please read the directions during the command 
          carefully, In many cases bad info can result 
          in an object that won't compile.
    Note 2: If you choose to exit in the middle of an 
            object all work will be lost and the file 
            erased. This is due to the fact that the file
            will be useless.
    Note 3: In selecting a base item type, please select 
            the item that has the mechanical attributes 
            you are seeking. Eg/ a +3 necklace would fall 
            under tailor, cloak - as it takes up this 
            equipment slot. The base item you select in 
            step 2 (unless a mundane object) will 
            designate the weight, ac, discern, prof, or 
            any other default attributes for you.
    Note 4: Please do NOT use jewelry items to carry 
            any innate bonuses, as these are stackable 
            items.");
   write("See also: alterobj, objects");
   return 1;
}
