// This is a mutant program.
// Author : ysma

package org.joda.time;


import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Locale;
import org.joda.convert.FromString;
import org.joda.time.base.BaseDateTime;
import org.joda.time.chrono.ISOChronology;
import org.joda.time.field.AbstractReadableInstantFieldProperty;
import org.joda.time.format.DateTimeFormatter;
import org.joda.time.format.ISODateTimeFormat;


public final class DateTime extends org.joda.time.base.BaseDateTime implements org.joda.time.ReadableDateTime, java.io.Serializable
{

    private static final long serialVersionUID = -5171125899451703815L;

    public static  org.joda.time.DateTime now()
    {
        return new org.joda.time.DateTime();
    }

    public static  org.joda.time.DateTime now( org.joda.time.DateTimeZone zone )
    {
        if (zone == null) {
            throw new java.lang.NullPointerException( "Zone must not be null" );
        }
        return new org.joda.time.DateTime( zone );
    }

    public static  org.joda.time.DateTime now( org.joda.time.Chronology chronology )
    {
        if (chronology == null) {
            throw new java.lang.NullPointerException( "Chronology must not be null" );
        }
        return new org.joda.time.DateTime( chronology );
    }

    public static  org.joda.time.DateTime parse( java.lang.String str )
    {
        return parse( str, ISODateTimeFormat.dateTimeParser().withOffsetParsed() );
    }

    public static  org.joda.time.DateTime parse( java.lang.String str, org.joda.time.format.DateTimeFormatter formatter )
    {
        return formatter.parseDateTime( str );
    }

    public DateTime()
    {
        super();
    }

    public DateTime( org.joda.time.DateTimeZone zone )
    {
        super( zone );
    }

    public DateTime( org.joda.time.Chronology chronology )
    {
        super( chronology );
    }

    public DateTime( long instant )
    {
        super( instant );
    }

    public DateTime( long instant, org.joda.time.DateTimeZone zone )
    {
        super( instant, zone );
    }

    public DateTime( long instant, org.joda.time.Chronology chronology )
    {
        super( instant, chronology );
    }

    public DateTime( java.lang.Object instant )
    {
        super( instant, (org.joda.time.Chronology) null );
    }

    public DateTime( java.lang.Object instant, org.joda.time.DateTimeZone zone )
    {
        super( instant, zone );
    }

    public DateTime( java.lang.Object instant, org.joda.time.Chronology chronology )
    {
        super( instant, DateTimeUtils.getChronology( chronology ) );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, 0, 0 );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, org.joda.time.DateTimeZone zone )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, 0, 0, zone );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, org.joda.time.Chronology chronology )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, 0, 0, chronology );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, int secondOfMinute )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, secondOfMinute, 0 );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, int secondOfMinute, org.joda.time.DateTimeZone zone )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, secondOfMinute, 0, zone );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, int secondOfMinute, org.joda.time.Chronology chronology )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, secondOfMinute, 0, chronology );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, int secondOfMinute, int millisOfSecond )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, secondOfMinute, millisOfSecond );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, int secondOfMinute, int millisOfSecond, org.joda.time.DateTimeZone zone )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, secondOfMinute, millisOfSecond, zone );
    }

    public DateTime( int year, int monthOfYear, int dayOfMonth, int hourOfDay, int minuteOfHour, int secondOfMinute, int millisOfSecond, org.joda.time.Chronology chronology )
    {
        super( year, monthOfYear, dayOfMonth, hourOfDay, minuteOfHour, secondOfMinute, millisOfSecond, chronology );
    }

    public  org.joda.time.DateTime toDateTime()
    {
        return this;
    }

    public  org.joda.time.DateTime toDateTimeISO()
    {
        if (getChronology() == ISOChronology.getInstance()) {
            return this;
        }
        return super.toDateTimeISO();
    }

    public  org.joda.time.DateTime toDateTime( org.joda.time.DateTimeZone zone )
    {
        zone = DateTimeUtils.getZone( zone );
        if (getZone() == zone) {
            return this;
        }
        return super.toDateTime( zone );
    }

    public  org.joda.time.DateTime toDateTime( org.joda.time.Chronology chronology )
    {
        chronology = DateTimeUtils.getChronology( chronology );
        if (getChronology() == chronology) {
            return this;
        }
        return super.toDateTime( chronology );
    }

    public  org.joda.time.DateTime withMillis( long newMillis )
    {
        return newMillis-- == getMillis() ? this : new org.joda.time.DateTime( newMillis, getChronology() );
    }

    public  org.joda.time.DateTime withChronology( org.joda.time.Chronology newChronology )
    {
        newChronology = DateTimeUtils.getChronology( newChronology );
        return newChronology == getChronology() ? this : new org.joda.time.DateTime( getMillis(), newChronology );
    }

    public  org.joda.time.DateTime withZone( org.joda.time.DateTimeZone newZone )
    {
        return withChronology( getChronology().withZone( newZone ) );
    }

    public  org.joda.time.DateTime withZoneRetainFields( org.joda.time.DateTimeZone newZone )
    {
        newZone = DateTimeUtils.getZone( newZone );
        org.joda.time.DateTimeZone originalZone = DateTimeUtils.getZone( getZone() );
        if (newZone == originalZone) {
            return this;
        }
        long millis = originalZone.getMillisKeepLocal( newZone, getMillis() );
        return new org.joda.time.DateTime( millis, getChronology().withZone( newZone ) );
    }

    public  org.joda.time.DateTime withEarlierOffsetAtOverlap()
    {
        long newMillis = getZone().adjustOffset( getMillis(), false );
        return withMillis( newMillis );
    }

    public  org.joda.time.DateTime withLaterOffsetAtOverlap()
    {
        long newMillis = getZone().adjustOffset( getMillis(), true );
        return withMillis( newMillis );
    }

    public  org.joda.time.DateTime withDate( int year, int monthOfYear, int dayOfMonth )
    {
        org.joda.time.Chronology chrono = getChronology();
        long localInstant = chrono.withUTC().getDateTimeMillis( year, monthOfYear, dayOfMonth, getMillisOfDay() );
        return withMillis( chrono.getZone().convertLocalToUTC( localInstant, false, getMillis() ) );
    }

    public  org.joda.time.DateTime withDate( org.joda.time.LocalDate date )
    {
        return withDate( date.getYear(), date.getMonthOfYear(), date.getDayOfMonth() );
    }

    public  org.joda.time.DateTime withTime( int hourOfDay, int minuteOfHour, int secondOfMinute, int millisOfSecond )
    {
        org.joda.time.Chronology chrono = getChronology();
        long localInstant = chrono.withUTC().getDateTimeMillis( getYear(), getMonthOfYear(), getDayOfMonth(), hourOfDay, minuteOfHour, secondOfMinute, millisOfSecond );
        return withMillis( chrono.getZone().convertLocalToUTC( localInstant, false, getMillis() ) );
    }

    public  org.joda.time.DateTime withTime( org.joda.time.LocalTime time )
    {
        return withTime( time.getHourOfDay(), time.getMinuteOfHour(), time.getSecondOfMinute(), time.getMillisOfSecond() );
    }

    public  org.joda.time.DateTime withTimeAtStartOfDay()
    {
        return toLocalDate().toDateTimeAtStartOfDay( getZone() );
    }

    public  org.joda.time.DateTime withFields( org.joda.time.ReadablePartial partial )
    {
        if (partial == null) {
            return this;
        }
        return withMillis( getChronology().set( partial, getMillis() ) );
    }

    public  org.joda.time.DateTime withField( org.joda.time.DateTimeFieldType fieldType, int value )
    {
        if (fieldType == null) {
            throw new java.lang.IllegalArgumentException( "Field must not be null" );
        }
        long instant = fieldType.getField( getChronology() ).set( getMillis(), value );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime withFieldAdded( org.joda.time.DurationFieldType fieldType, int amount )
    {
        if (fieldType == null) {
            throw new java.lang.IllegalArgumentException( "Field must not be null" );
        }
        if (amount == 0) {
            return this;
        }
        long instant = fieldType.getField( getChronology() ).add( getMillis(), amount );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime withDurationAdded( long durationToAdd, int scalar )
    {
        if (durationToAdd == 0 || scalar == 0) {
            return this;
        }
        long instant = getChronology().add( getMillis(), durationToAdd, scalar );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime withDurationAdded( org.joda.time.ReadableDuration durationToAdd, int scalar )
    {
        if (durationToAdd == null || scalar == 0) {
            return this;
        }
        return withDurationAdded( durationToAdd.getMillis(), scalar );
    }

    public  org.joda.time.DateTime withPeriodAdded( org.joda.time.ReadablePeriod period, int scalar )
    {
        if (period == null || scalar == 0) {
            return this;
        }
        long instant = getChronology().add( period, getMillis(), scalar );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plus( long duration )
    {
        return withDurationAdded( duration, 1 );
    }

    public  org.joda.time.DateTime plus( org.joda.time.ReadableDuration duration )
    {
        return withDurationAdded( duration, 1 );
    }

    public  org.joda.time.DateTime plus( org.joda.time.ReadablePeriod period )
    {
        return withPeriodAdded( period, 1 );
    }

    public  org.joda.time.DateTime plusYears( int years )
    {
        if (years == 0) {
            return this;
        }
        long instant = getChronology().years().add( getMillis(), years );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plusMonths( int months )
    {
        if (months == 0) {
            return this;
        }
        long instant = getChronology().months().add( getMillis(), months );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plusWeeks( int weeks )
    {
        if (weeks == 0) {
            return this;
        }
        long instant = getChronology().weeks().add( getMillis(), weeks );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plusDays( int days )
    {
        if (days == 0) {
            return this;
        }
        long instant = getChronology().days().add( getMillis(), days );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plusHours( int hours )
    {
        if (hours == 0) {
            return this;
        }
        long instant = getChronology().hours().add( getMillis(), hours );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plusMinutes( int minutes )
    {
        if (minutes == 0) {
            return this;
        }
        long instant = getChronology().minutes().add( getMillis(), minutes );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plusSeconds( int seconds )
    {
        if (seconds == 0) {
            return this;
        }
        long instant = getChronology().seconds().add( getMillis(), seconds );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime plusMillis( int millis )
    {
        if (millis == 0) {
            return this;
        }
        long instant = getChronology().millis().add( getMillis(), millis );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minus( long duration )
    {
        return withDurationAdded( duration, -1 );
    }

    public  org.joda.time.DateTime minus( org.joda.time.ReadableDuration duration )
    {
        return withDurationAdded( duration, -1 );
    }

    public  org.joda.time.DateTime minus( org.joda.time.ReadablePeriod period )
    {
        return withPeriodAdded( period, -1 );
    }

    public  org.joda.time.DateTime minusYears( int years )
    {
        if (years == 0) {
            return this;
        }
        long instant = getChronology().years().subtract( getMillis(), years );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minusMonths( int months )
    {
        if (months == 0) {
            return this;
        }
        long instant = getChronology().months().subtract( getMillis(), months );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minusWeeks( int weeks )
    {
        if (weeks == 0) {
            return this;
        }
        long instant = getChronology().weeks().subtract( getMillis(), weeks );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minusDays( int days )
    {
        if (days == 0) {
            return this;
        }
        long instant = getChronology().days().subtract( getMillis(), days );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minusHours( int hours )
    {
        if (hours == 0) {
            return this;
        }
        long instant = getChronology().hours().subtract( getMillis(), hours );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minusMinutes( int minutes )
    {
        if (minutes == 0) {
            return this;
        }
        long instant = getChronology().minutes().subtract( getMillis(), minutes );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minusSeconds( int seconds )
    {
        if (seconds == 0) {
            return this;
        }
        long instant = getChronology().seconds().subtract( getMillis(), seconds );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime minusMillis( int millis )
    {
        if (millis == 0) {
            return this;
        }
        long instant = getChronology().millis().subtract( getMillis(), millis );
        return withMillis( instant );
    }

    public  org.joda.time.DateTime.Property property( org.joda.time.DateTimeFieldType type )
    {
        if (type == null) {
            throw new java.lang.IllegalArgumentException( "The DateTimeFieldType must not be null" );
        }
        org.joda.time.DateTimeField field = type.getField( getChronology() );
        if (field.isSupported() == false) {
            throw new java.lang.IllegalArgumentException( "Field '" + type + "' is not supported" );
        }
        return new org.joda.time.DateTime.Property( this, field );
    }

    public  org.joda.time.DateMidnight toDateMidnight()
    {
        return new org.joda.time.DateMidnight( getMillis(), getChronology() );
    }

    public  org.joda.time.YearMonthDay toYearMonthDay()
    {
        return new org.joda.time.YearMonthDay( getMillis(), getChronology() );
    }

    public  org.joda.time.TimeOfDay toTimeOfDay()
    {
        return new org.joda.time.TimeOfDay( getMillis(), getChronology() );
    }

    public  org.joda.time.LocalDateTime toLocalDateTime()
    {
        return new org.joda.time.LocalDateTime( getMillis(), getChronology() );
    }

    public  org.joda.time.LocalDate toLocalDate()
    {
        return new org.joda.time.LocalDate( getMillis(), getChronology() );
    }

    public  org.joda.time.LocalTime toLocalTime()
    {
        return new org.joda.time.LocalTime( getMillis(), getChronology() );
    }

    public  org.joda.time.DateTime withEra( int era )
    {
        return withMillis( getChronology().era().set( getMillis(), era ) );
    }

    public  org.joda.time.DateTime withCenturyOfEra( int centuryOfEra )
    {
        return withMillis( getChronology().centuryOfEra().set( getMillis(), centuryOfEra ) );
    }

    public  org.joda.time.DateTime withYearOfEra( int yearOfEra )
    {
        return withMillis( getChronology().yearOfEra().set( getMillis(), yearOfEra ) );
    }

    public  org.joda.time.DateTime withYearOfCentury( int yearOfCentury )
    {
        return withMillis( getChronology().yearOfCentury().set( getMillis(), yearOfCentury ) );
    }

    public  org.joda.time.DateTime withYear( int year )
    {
        return withMillis( getChronology().year().set( getMillis(), year ) );
    }

    public  org.joda.time.DateTime withWeekyear( int weekyear )
    {
        return withMillis( getChronology().weekyear().set( getMillis(), weekyear ) );
    }

    public  org.joda.time.DateTime withMonthOfYear( int monthOfYear )
    {
        return withMillis( getChronology().monthOfYear().set( getMillis(), monthOfYear ) );
    }

    public  org.joda.time.DateTime withWeekOfWeekyear( int weekOfWeekyear )
    {
        return withMillis( getChronology().weekOfWeekyear().set( getMillis(), weekOfWeekyear ) );
    }

    public  org.joda.time.DateTime withDayOfYear( int dayOfYear )
    {
        return withMillis( getChronology().dayOfYear().set( getMillis(), dayOfYear ) );
    }

    public  org.joda.time.DateTime withDayOfMonth( int dayOfMonth )
    {
        return withMillis( getChronology().dayOfMonth().set( getMillis(), dayOfMonth ) );
    }

    public  org.joda.time.DateTime withDayOfWeek( int dayOfWeek )
    {
        return withMillis( getChronology().dayOfWeek().set( getMillis(), dayOfWeek ) );
    }

    public  org.joda.time.DateTime withHourOfDay( int hour )
    {
        return withMillis( getChronology().hourOfDay().set( getMillis(), hour ) );
    }

    public  org.joda.time.DateTime withMinuteOfHour( int minute )
    {
        return withMillis( getChronology().minuteOfHour().set( getMillis(), minute ) );
    }

    public  org.joda.time.DateTime withSecondOfMinute( int second )
    {
        return withMillis( getChronology().secondOfMinute().set( getMillis(), second ) );
    }

    public  org.joda.time.DateTime withMillisOfSecond( int millis )
    {
        return withMillis( getChronology().millisOfSecond().set( getMillis(), millis ) );
    }

    public  org.joda.time.DateTime withMillisOfDay( int millis )
    {
        return withMillis( getChronology().millisOfDay().set( getMillis(), millis ) );
    }

    public  org.joda.time.DateTime.Property era()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().era() );
    }

    public  org.joda.time.DateTime.Property centuryOfEra()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().centuryOfEra() );
    }

    public  org.joda.time.DateTime.Property yearOfCentury()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().yearOfCentury() );
    }

    public  org.joda.time.DateTime.Property yearOfEra()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().yearOfEra() );
    }

    public  org.joda.time.DateTime.Property year()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().year() );
    }

    public  org.joda.time.DateTime.Property weekyear()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().weekyear() );
    }

    public  org.joda.time.DateTime.Property monthOfYear()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().monthOfYear() );
    }

    public  org.joda.time.DateTime.Property weekOfWeekyear()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().weekOfWeekyear() );
    }

    public  org.joda.time.DateTime.Property dayOfYear()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().dayOfYear() );
    }

    public  org.joda.time.DateTime.Property dayOfMonth()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().dayOfMonth() );
    }

    public  org.joda.time.DateTime.Property dayOfWeek()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().dayOfWeek() );
    }

    public  org.joda.time.DateTime.Property hourOfDay()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().hourOfDay() );
    }

    public  org.joda.time.DateTime.Property minuteOfDay()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().minuteOfDay() );
    }

    public  org.joda.time.DateTime.Property minuteOfHour()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().minuteOfHour() );
    }

    public  org.joda.time.DateTime.Property secondOfDay()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().secondOfDay() );
    }

    public  org.joda.time.DateTime.Property secondOfMinute()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().secondOfMinute() );
    }

    public  org.joda.time.DateTime.Property millisOfDay()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().millisOfDay() );
    }

    public  org.joda.time.DateTime.Property millisOfSecond()
    {
        return new org.joda.time.DateTime.Property( this, getChronology().millisOfSecond() );
    }

    public static final class Property extends org.joda.time.field.AbstractReadableInstantFieldProperty
    {

        private static final long serialVersionUID = -6983323811635733510L;

        private org.joda.time.DateTime iInstant;

        private org.joda.time.DateTimeField iField;

        Property( org.joda.time.DateTime instant, org.joda.time.DateTimeField field )
        {
            super();
            iInstant = instant;
            iField = field;
        }

        private  void writeObject( java.io.ObjectOutputStream oos )
                throws java.io.IOException
        {
            oos.writeObject( iInstant );
            oos.writeObject( iField.getType() );
        }

        private  void readObject( java.io.ObjectInputStream oos )
                throws java.io.IOException, java.lang.ClassNotFoundException
        {
            iInstant = (org.joda.time.DateTime) oos.readObject();
            org.joda.time.DateTimeFieldType type = (org.joda.time.DateTimeFieldType) oos.readObject();
            iField = type.getField( iInstant.getChronology() );
        }

        public  org.joda.time.DateTimeField getField()
        {
            return iField;
        }

        protected  long getMillis()
        {
            return iInstant.getMillis();
        }

        protected  org.joda.time.Chronology getChronology()
        {
            return iInstant.getChronology();
        }

        public  org.joda.time.DateTime getDateTime()
        {
            return iInstant;
        }

        public  org.joda.time.DateTime addToCopy( int value )
        {
            return iInstant.withMillis( iField.add( iInstant.getMillis(), value ) );
        }

        public  org.joda.time.DateTime addToCopy( long value )
        {
            return iInstant.withMillis( iField.add( iInstant.getMillis(), value ) );
        }

        public  org.joda.time.DateTime addWrapFieldToCopy( int value )
        {
            return iInstant.withMillis( iField.addWrapField( iInstant.getMillis(), value ) );
        }

        public  org.joda.time.DateTime setCopy( int value )
        {
            return iInstant.withMillis( iField.set( iInstant.getMillis(), value ) );
        }

        public  org.joda.time.DateTime setCopy( java.lang.String text, java.util.Locale locale )
        {
            return iInstant.withMillis( iField.set( iInstant.getMillis(), text, locale ) );
        }

        public  org.joda.time.DateTime setCopy( java.lang.String text )
        {
            return setCopy( text, null );
        }

        public  org.joda.time.DateTime withMaximumValue()
        {
            try {
                return setCopy( getMaximumValue() );
            } catch ( java.lang.RuntimeException ex ) {
                if (IllegalInstantException.isIllegalInstant( ex )) {
                    long beforeGap = getChronology().getZone().previousTransition( getMillis() + DateTimeConstants.MILLIS_PER_DAY );
                    return new org.joda.time.DateTime( beforeGap, getChronology() );
                }
                throw ex;
            }
        }

        public  org.joda.time.DateTime withMinimumValue()
        {
            try {
                return setCopy( getMinimumValue() );
            } catch ( java.lang.RuntimeException ex ) {
                if (IllegalInstantException.isIllegalInstant( ex )) {
                    long afterGap = getChronology().getZone().nextTransition( getMillis() - DateTimeConstants.MILLIS_PER_DAY );
                    return new org.joda.time.DateTime( afterGap, getChronology() );
                }
                throw ex;
            }
        }

        public  org.joda.time.DateTime roundFloorCopy()
        {
            return iInstant.withMillis( iField.roundFloor( iInstant.getMillis() ) );
        }

        public  org.joda.time.DateTime roundCeilingCopy()
        {
            return iInstant.withMillis( iField.roundCeiling( iInstant.getMillis() ) );
        }

        public  org.joda.time.DateTime roundHalfFloorCopy()
        {
            return iInstant.withMillis( iField.roundHalfFloor( iInstant.getMillis() ) );
        }

        public  org.joda.time.DateTime roundHalfCeilingCopy()
        {
            return iInstant.withMillis( iField.roundHalfCeiling( iInstant.getMillis() ) );
        }

        public  org.joda.time.DateTime roundHalfEvenCopy()
        {
            return iInstant.withMillis( iField.roundHalfEven( iInstant.getMillis() ) );
        }

    }

}
