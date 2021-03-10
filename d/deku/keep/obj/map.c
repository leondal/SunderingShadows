#include <std.h>
inherit OBJECT;

string *orooms = ({"15-5", "23-5", "21-2", "8-9", "32-15", "37-22", "37-19"});

string create_location(string place, string *locs, int mis)
{
    int x, y, m, z = 0, *nums = ({37, 2, 22, 1}), w = 0, t = 0;
    string *parray;
    while(z == 0 && mis == 1)
    {
        parray = explode(place, "-");
        w = 0;
        x = 0;
        for(y = 0;y < 4;y++)
        {
            x = to_int(parray[w]);
            m = (random(3) + 1);
            if(x + m > nums[y]) 
            {
                x -= m;
            }
            else if(x - m < nums[y+1])
            {
                x += m;
            }
            else 
            {
                switch(random(2)) 
                {
                    case 0:
                        x += m;
                        break;
                    case 1:
                        x -= m;
                        break;
                    default:
                        break;
                }
            }
            parray[w] = x + "";
            //tell_object(ETO, "Parray[w] = "+parray[w]);
            w++;
            y = y + 2;			
        }
        if(member_array(implode(parray, "-"), locs) != -1)
        {
            z = 1;
            place = implode(parray, "-");
        }
        t++;
        //Infinite loop = bad - if it's went through 3 times without finding
        //a nearby location then terminate the loop and pick a random location
        //better than breaking the mud - Saide
        if(t == 3)
        {
            place = locs[random(sizeof(locs))];
            z = 1;
        }
    }
    if(mis == 2)
    {
        place = locs[random(sizeof(locs))];
    }
    return place;
}

string repeat_string(string str, int x)
{
    int y;
    string nstr = "";
    for(y = 0;y < x;y++)
    {
        nstr += str;
    }
    return nstr;
}

string query_long(string str)
{
    object where, room, *liv;
    string tmp, *files, *parts = ({}), file, leg, place;
    int l = 40, w = 19, y = 41, x, z, m, it, wi, r_place;
    where = EETO;
    if(!objectp(where)) 
    {
        return "This piece of parchment looks blank, perhaps "+
        "try picking it up and getting a closer look at it.";
    }
    place = replace_string(base_name(where), "/d/deku/forest/dforest", "");
    tmp = repeat_string("-", 45) + "\n";
    files = get_dir("/d/deku/forest/");
    for(x = 0;x < sizeof(files);x++)
    {
        file = files[x];
        if(strsrch(file, "dforest") != -1)
        {
            file = replace_string(file, "dforest", "");
            file = replace_string(file, ".c", "");
            if(to_int(explode(file, "-")[1]) < 17) 
            {
                parts += ({file});
            }
        }	
    }
    if(strlen(place) <= 5 && member_array(place, parts) != -1)
    {
        it = ETO->query_stats("intelligence");
        wi = ETO->query_stats("wisdom");
        m = random(30) + 4;
        if((it + wi) < m)
        {
            //Total Failure - location can be WAAAAYYYYY OFF - Saide 
            if(m > (it + wi + 5)) 
            {
                place = create_location(place,parts,1); 
            }	
            //Failure - but relatively accurate location - Saide
            else 
            {
                place = create_location(place,parts,1);
            }
        }	
    }
    while(l != -3 && w != -3)
    {
        y --;
        if(y == 40)
        {
            tmp += "|";
        }
        if(y == -3)
        {
            tmp += "|\n|";
            y = 40;
        }
        if((x = member_array(l + "-" + w, parts)) != -1 && w < 17)
        {
            if(objectp(where)) 
            {
                //r_place = random(100);
                if(parts[x] == place)
                {
                    tmp += "%^BOLD%^%^RED%^@%^RESET%^";
                }
                else if(member_array(parts[x], orooms) == -1 && r_place != 23)						
                {
                    if(objectp(room = find_object("/d/deku/forest/dforest"+l+"-"+w))) 
                    {   
                        liv = all_living(room);
                        if(sizeof(liv) && member_array(ETO, liv) == -1) 
                        {
                            tmp += "L";
                        }
                        else 
                        {
                            tmp += "%^GREEN%^F%^RESET%^";
                        }
                    }
                    else
                    {
                        tmp += "%^GREEN%^F%^RESET%^";
                    }
                }
                else if(member_array(parts[x], orooms) != -1 || r_place == 23)
                {
                    tmp += "%^BOLD%^%^MAGENTA%^P%^RESET%^";
                }
            }
        }
        else 
        {
            tmp += " ";
        }
        l--;
        if(l == -3 && w != -3)
        {
            w--;
            l = 40;
        }
    }	
    leg = "%^CYAN%^Map Legend %^RESET%^:\n"+
    "%^GREEN%^F = Forest%^RESET%^\n"+
    "%^BOLD%^%^MAGENTA%^P = Place of Interest%^RESET%^\n"+
    "L = Life Detected\n"+
    "%^BOLD%^%^RED%^@ = Your Location%^RESET%^\n";
    tmp += "|\n" + 
    repeat_string("-", 45) + "\n";
    write("\t%^BOLD%^%^GREEN%^Map of The Shadowlord Forest%^RESET%^");
    write("\n"+tmp);
    write(leg);
    return "";
}

void create() 
{
    ::create();
    set_name("A map of the deku forest");
    set_id( ({"map", "deku map", "worn map"}) );
    set_short("A worn map of the deku forest");
	//set_long((:TO, "long_desc":));
    set_weight(1);
    set_value(10);
}