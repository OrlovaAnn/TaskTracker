#include "taskfilterfactory.h"
#include "taskfilter.h"

namespace Model
{

    TaskFilterFactory& TaskFilterFactory::get()
    {
        static TaskFilterFactory factory;
        return factory;
    }

}
