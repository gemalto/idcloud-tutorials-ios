/** -----------------------------------------------------------------------------
 
 Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
 
 -----------------------------------------------------------------------------
 GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 
 THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 HIGH RISK ACTIVITIES.
 
 -----------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>
#import "EMSecureByteArray.h"

/**
 * A protocol representing a secure container object in memory.
 */
@protocol EMSecureString <EMSecureByteArray>

/**
 * Returns a deep copy of the the value of data as an immutable `NSString`.
 *
 * @warning This method creates an immutable string which can be a potential security issue. Use CAREFULLY as this `NSString` cannot be wiped from memory even after sending -wipe to the `EMSecureString` object.
 * @return An immutable `NSString` representation of the object.
 */
- (NSString *)stringValue;

/**
 * Returns the length of the data in number of characters.
 *
 * @return Number of characters in the string.
 */
- (NSUInteger)stringLength;

/**
 * Appends `EMSecureString` object with another `EMSecureString` object.
 *
 * @warning `EMSecureString` objects that has been created with a custom string encoding (using [EMSecureDataFactory secureStringWithString:encoding:]) cannot be the receiver or data argument of this method.
 *
 * @param anotherString The secure string to append.
 *
 * @return The new `EMSecureString` object containing the concatenation of the two secure strings.
 */
- (id<EMSecureString>)append:(id<EMSecureString>) anotherString;

@end
