#ifndef _PACMAN_PORTALMODEL_
#define _PACMAN_PORTALMODEL_

#include "ObjectModel.h"

class PortalModel : public ObjectModel
{
protected:
	void DoDraw();

public:
	PortalModel(void);
	~PortalModel(void);

};

#endif

