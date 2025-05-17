#include <Router.h>

void Router::setRoute(std::string name, bool clear = false) {
  if (clear)
    history.clear();
  history.push_back(routeMap.at(name));
}

Router::Router(History routes, History restoredhistory = {}) {
  for (Route r : routes) {
    routeMap[r.name] = r;
  }

  history = restoredhistory;
}

Route Router::getRoute() { return history.back(); }

bool Router::back() {
  if (history.size() < 2) {
    return false;
  }

  history.pop_back();
  return true;
}
