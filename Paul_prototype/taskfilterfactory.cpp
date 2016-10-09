#include "taskfilterfactory.h"

namespace Model
{

    TaskFilterFactory& TaskFilterFactory::get()
    {
        static TaskFilterFactory factory;
        return factory;
    }

}
