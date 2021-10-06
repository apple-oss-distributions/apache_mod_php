/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2008 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Christian Stocker <chregu@php.net>                          |
   |          Rob Richards <rrichards@php.net>                            |
   +----------------------------------------------------------------------+
*/

/* $Id: domerrorhandler.c,v 1.5.2.1.2.3 2008/02/04 15:23:11 sebastian Exp $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#if HAVE_LIBXML && HAVE_DOM
#include "php_dom.h"


/* {{{ arginfo */
static
ZEND_BEGIN_ARG_INFO_EX(arginfo_dom_domerrorhandler_handle_error, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, error, DOMError, 0)
ZEND_END_ARG_INFO();
/* }}} */

/*
* class domerrorhandler 
*
* URL: http://www.w3.org/TR/2003/WD-DOM-Level-3-Core-20030226/DOM3-Core.html#ERROR-Interfaces-DOMErrorHandler
* Since: DOM Level 3
*/

zend_function_entry php_dom_domerrorhandler_class_functions[] = {
	PHP_FALIAS(handleError, dom_domerrorhandler_handle_error, arginfo_dom_domerrorhandler_handle_error)
	{NULL, NULL, NULL}
};

/* {{{ attribute protos, not implemented yet */


/* {{{ proto dom_boolean dom_domerrorhandler_handle_error(domerror error);
URL: http://www.w3.org/TR/2003/WD-DOM-Level-3-Core-20030226/DOM3-Core.html#ID-ERRORS-DOMErrorHandler-handleError
Since: 
*/
PHP_FUNCTION(dom_domerrorhandler_handle_error)
{
 DOM_NOT_IMPLEMENTED();
}
/* }}} end dom_domerrorhandler_handle_error */
#endif
