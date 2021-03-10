//This is namegen stolen from Elite
//Well, re-implemented

#define RTH_MAX_NAMES 256

nosave private string *rth_pairs_arr = ({
/* Planets from the original Elite */
        "..lexegezacebiso" +
            "usesarmaindirea." +
            "eratenberalaveti" +
            "edorquanteisrion",
/* Lorem ipsum */
            "..qupeaudidoliut" +
            "viadaedupasotoa." +
            "loaregelpufridhe" +
            "geimmeneninopier",
/* War and Peace */
            "..hethineranrena" +
            "ouonedneathatoa." +
            "isenitasteesaror" +
            "lenistverineseli",
/* Front page of Boing Boing (including HTML) */
            "..indiennatehaiv" +
            "bonereanasthoia." +
            "celaeterpariryte" +
            "atlehesetaarcoes",
/* The Little Prince (Chapters 1-5, English version) */
            "..thheanerinhaat" +
            "reouisittoonvea." +
            "histedleennamees" +
            "nenoofearoseorar",
            });

nosave private string rth_pairs;

nosave private mapping rth_seed = ([
                                       "w0": 0,
                                       "w1": 0,
                                       "w2": 0,
                                       ]);

protected int rth_rotatel(int x)
{
    x = (x & 255) * 2;
    if(x > 255) x -= 255;
    return x;
}

protected int rth_twist(int x)
{
    return (rth_rotatel(x >> 8) << 8) + rth_rotatel(x & 255);
}

protected void rth_next()
{
    rth_seed["w0"] = rth_twist(rth_seed["w0"]);
    rth_seed["w1"] = rth_twist(rth_seed["w1"]);
    rth_seed["w2"] = rth_twist(rth_seed["w2"]);
}

protected void rth_tweakseed()
{
    int tmp;

    tmp = rth_seed["w0"] + rth_seed["w1"] + rth_seed["w2"];
    tmp &= 65535;

    rth_seed["w0"] = rth_seed["w1"];
    rth_seed["w1"] = rth_seed["w2"];
    rth_seed["w2"] = tmp;
}

protected string rth_makename()
{
    string name;
    int pair1, pair2, pair3, pair4;
    int longname = rth_seed["w0"] & 64;

    /* Always 4 iterations of random number */
    pair1 = 2 * ((rth_seed["w2"] >> 8) & 31); rth_tweakseed();
    pair2 = 2 * ((rth_seed["w2"] >> 8) & 31); rth_tweakseed();
    pair3 = 2 * ((rth_seed["w2"] >> 8) & 31); rth_tweakseed();
    pair4 = 2 * ((rth_seed["w2"] >> 8) & 31); rth_tweakseed();

    name  = sprintf("%c", rth_pairs[pair1]);
    name += sprintf("%c", rth_pairs[pair1 + 1]);
    name += sprintf("%c", rth_pairs[pair2]);
    name += sprintf("%c", rth_pairs[pair2 + 1]);
    name += sprintf("%c", rth_pairs[pair3]);
    name += sprintf("%c", rth_pairs[pair3 + 1]);

    /* bit 6 of ORIGINAL w0 flags a four-pair name */
    if (longname)
    {
        name += sprintf("%c", rth_pairs[pair4]);
        name += sprintf("%c", rth_pairs[pair4 + 1]);
    }

    /* Remove any '.' in the name and capitalize the result */
    name = capitalize(replace_string(name, ".", ""));

    return name;
}

varargs string generate_name(int pair, int num, int ind)
{
    string *names = allocate(RTH_MAX_NAMES);

    if(undefinedp(pair) || !intp(pair)) pair = random(sizeof(rth_pairs_arr));
    if(pair < 0 || pair >= sizeof(rth_pairs_arr)) pair = 0;

    rth_pairs = rth_pairs_arr[pair];

    if(undefinedp(num) || !intp(num)) num = random(8) + 1;
    if(num < 1 || num > 8) num = 1;

    rth_seed["w0"] = 0x5a4a;
    rth_seed["w1"] = 0x0248;
    rth_seed["w2"] = 0xb753;

    for (int i = 1 ; i < num ; ++i) rth_next();

    for (int i = 0 ; i < RTH_MAX_NAMES ; ++i)
        names[i] = rth_makename();

    if (undefinedp(ind) || !intp(ind)) ind = random(RTH_MAX_NAMES);
    if (ind < 0 || ind >= RTH_MAX_NAMES) ind = 0;

    return names[ind];
}
