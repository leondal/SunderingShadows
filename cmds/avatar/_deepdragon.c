#include <std.h>

#define LOC "/d/underdark/lower/dragon/obj/"


string *files = ({ "alignamulet","geniescuff","shadowdancer","barrier","sheoldagger","chargegem","greaterrop","shimmaryn","gsunblade",
    "decanter","lance","spellbracelets","dustbox","lenses","stonebreaker","flamebow","marhtesa","stoneplate","gauntlets","mendingprism",
    "telepathycirclet","tpboots","weaponring" });

int id_stuff(object tp);


int cmd_deepdragon(string str) 
{
    string *names=({});
    object *ppl=({}),obj;
    int i;

    if(!str || str == "" || str == " ")
    {
        ppl = all_living(ETP);
        
        for(i=0;i<sizeof(ppl);i++)
        {
            if(!objectp(ppl[i])) { continue; }
            names += ({ ppl[i]->query_true_name() });
        }
    }
    else
    {
        names = explode(str," ");
    }

    for(i=0;i<sizeof(files);i++)
    {
        obj = new(LOC+files[i]+".c");
        obj->move(ETP);
        obj->bind_me(names);
    }

    id_stuff(TP);
    return 1;
}

int id_stuff(object tp)
{
    object *objs,*ppl;
    int i,j;

    objs = all_inventory(environment(tp));

    for(i=0;i<sizeof(objs);i++)
    {
        if(!objectp(objs[i])) { continue; }
        if(living(objs[i])) { continue; }


        ppl = all_inventory(environment(tp));
        for (j = 0;j < sizeof(ppl);j++) 
        {
            if (interactive(ppl[j]))
            {
                objs[i]->add_identified(ppl[j]->query_name());
            }
        }
    }

    tell_room(environment(tp),"%^CYAN%^"+tp->QCN+" waves "+tp->QP+" hand and reveals the magical properties of "
        "everything in the room.");
    return 1;
}

int help(string str)
{
    write("Syntax: deepdragon | deepdragon <name1> <name2> ... <nameN> \n\n"
        "This command will spawn all of the items from Nienne's dragon and bind them to "
        "everyone in the room if no names are passed.  Else it will bind them to the names "
        "provided.  Names should be separated by spaces only.");

}



