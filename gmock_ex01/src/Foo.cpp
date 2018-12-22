/*
 *
 */

#include "Foo.h"
#include "Bar.h"

Foo::Foo(std::unique_ptr<IBar> bar) : bar(std::move(bar)) {

}

void Foo::DoIt() {
    bar->DoSth();
}
