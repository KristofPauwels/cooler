#ifndef GSMULTIPLAYERCHOICE_H
#define GSMULTIPLAYERCHOICE_H

#include <AbstractGameState.h>

#include "GSMenu.h"

class QGraphicsPixmapItem;

class GSMultiPlayerChoice : public AbstractGameState
{
public:
	static GSMultiPlayerChoice* instance();
	
	virtual void Init( GameEngine* engine, const QSizeF& size );
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents( GameEngine* game );
	virtual void Update( GameEngine* game );

protected:
	static GSMultiPlayerChoice* mInstance;
	
	int mBackgroundValue;
	QPixmap mBackground;
	
	QGraphicsLinearLayout* mMainLayout;
	GSMenuItem* mTitle;
	QGraphicsLinearLayout* mMenuLayout;
	GSMenu* mPlayersMenu;
	GSMenu* mStatesMenu;
	
	virtual void paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0 );
	bool validateSettings( GameEngine* engine ) const;
};

#endif // GSMULTIPLAYERCHOICE_H