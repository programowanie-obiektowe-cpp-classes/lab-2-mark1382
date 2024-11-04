// ResourceManager.hpp

#include <memory>
#include "Resource.hpp"

class ResourceManager {
private:
    std::unique_ptr<Resource> resource; // Inteligentny wskaźnik zarządzający zasobem

public:
    // Konstruktor domyślny
    ResourceManager() : resource(std::make_unique<Resource>()) {}

    // Kopiujący konstruktor
    ResourceManager(const ResourceManager& other) : resource(std::make_unique<Resource>(*other.resource)) {}

    // Przenoszący konstruktor
    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        return *this;
    }

    // Operator przypisania przenoszący
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get, która zwraca wynik metody get() klasy Resource
    double get() const {
        return resource->get();
    }
};
