
export function GenerateConstructor(e)
{
    for(const key in e)
    {
        this[key]=e[key];
    }
}