/*
  +----------------------------------------------------------------------+
  | PHP Version 4                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2003 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.02 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available at through the world-wide-web at                           |
  | http://www.php.net/license/2_02.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+

  $Id: php_mime_magic.h,v 1.4.4.2 2003/11/04 05:15:55 sniper Exp $ 
*/

#ifndef PHP_MIME_MAGIC_H
#define PHP_MIME_MAGIC_H

extern zend_module_entry mime_magic_module_entry;
#define phpext_mime_magic_ptr &mime_magic_module_entry

#ifdef PHP_WIN32
#define PHP_MIME_MAGIC_API __declspec(dllexport)
#else
#define PHP_MIME_MAGIC_API
#endif

PHP_MINIT_FUNCTION(mime_magic);
PHP_MSHUTDOWN_FUNCTION(mime_magic);
PHP_RINIT_FUNCTION(mime_magic);
PHP_RSHUTDOWN_FUNCTION(mime_magic);
PHP_MINFO_FUNCTION(mime_magic);

PHP_FUNCTION(mime_content_type);	

#endif	/* PHP_MIME_MAGIC_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
