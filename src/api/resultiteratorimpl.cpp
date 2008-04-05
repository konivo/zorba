#include <zorba/item.h>

#include "api/resultiteratorimpl.h"
#include "api/zorbaimpl.h"

#include "store/api/item.h"
#include "runtime/api/plan_wrapper.h"
#include "errors/error_manager.h"

namespace zorba {

  ResultIteratorImpl::ResultIteratorImpl(const PlanWrapper_t& aPlanWrapper,
                                         error::ErrorManager* aErrorManager,
                                         ErrorHandler* aErrorHandler)
    : thePlan(aPlanWrapper),
      theIsOpened(false),
      theErrorManager(aErrorManager),
      theErrorHandler(aErrorHandler) {}

  ResultIteratorImpl::~ResultIteratorImpl() 
  {
    if (theIsOpened)
      thePlan->close();
  }
 
  void 
  ResultIteratorImpl::open()
  {
    if ( ! theIsOpened ) {
      thePlan->open();
      theIsOpened = true;
    } 
  }

  bool
  ResultIteratorImpl::next(Item& aItem)
  {
    store::Item_t lItem;
    try 
    {
      if (!theIsOpened) 
        return false; // todo throw error here

      lItem = thePlan->next();
    }
    catch (error::ZorbaError& e)
    {
      ZorbaImpl::notifyError(theErrorHandler, e);
      return false; // if no exception is thrown in the error handler
    }

    if (lItem == NULL)
      return false;
    
    if (lItem->isPul())
      ZORBA_ERROR(ZorbaError::API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY);

    aItem = &*lItem;

    return true;
  }

  void 
  ResultIteratorImpl::close()
  {
    if (theIsOpened) {
      thePlan->reset();
    }
  }

} /* namespace zorba */
