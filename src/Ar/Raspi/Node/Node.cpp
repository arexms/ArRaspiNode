/**
    @author arex
    @project ArRaspiNode
*/

#include <Ar/Raspi/Node/Node.h>
#include <iostream>

namespace Ar { namespace Raspi { namespace Node
{
    Node::Node()
    {
        std::cout << "Node::Node()" << std::endl;
    }

    bool Node::start(int x)
    {
        if(x == 0)
        {
            return false;
        }

        std::cout << "RUN";

        return true;
    }
    
}}}
