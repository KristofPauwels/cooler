#ifndef GSMULTIPLAYGROUND_H
#define GSMULTIPLAYGROUND_H

#include "AbstractGameState.h"
#include "GSMenuItem.h"

class QGraphicsLinearLayout;
class GSMapItem;

class GSMultiPlayGround : public AbstractGameState
{
public:
	static GSMultiPlayGround* instance();
	
	virtual void Init( GameEngine* engine, const QSizeF& size );
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents( GameEngine* game );
	virtual void Update( GameEngine* game );
	virtual bool validateState( GameEngine* game ) const;

protected:
	static GSMultiPlayGround* mInstance;
	
	int mBackgroundValue;
	QPixmap mBackground;
	
	QGraphicsLinearLayout* mMainLayout;
	GSMenuItem* mTitle;
	
	virtual void paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0 );
};

#endif // GSMULTIPLAYGROUND_H