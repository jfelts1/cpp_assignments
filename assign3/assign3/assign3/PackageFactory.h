#ifndef PACKAGEFACTORY_H
#define PACKAGEFACTORY_H
#include "Box.h"
#include "Crate.h"
#include "Letter.h"
#include "MetalCrate.h"
#include "PackageException.h"
#include "WoodCrate.h"
#include "Truck.h"
#include <vector>
#include <memory>
#include <string>

std::unique_ptr<Package>& packageFactory(std::vector<std::string> s);



#endif