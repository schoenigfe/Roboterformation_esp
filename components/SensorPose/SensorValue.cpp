/* #include "SensorValue.h"

       
template <typename T>
bool SensorValue<T>::peekAtValue(T& current_value)
{
	if(xQueuePeek(_peek_at_value_queue, &current_value, 0) == pdPASS)	
		return true;
	return false;
}
		
template <typename T>
bool SensorValue<T>::getValue(T& current_value)
{
	if(xQueueReceive(_current_value_queue, &current_value, 0) == pdPASS)	
		return true;
	return false;
}

template <typename T>
void SensorValue<T>::overwriteValue(T& new_value)
{
	xQueueOverwrite(_peek_at_value_queue, &new_value);
	xQueueOverwrite(_current_value_queue, &new_value);
}
        		
template <typename T>
SensorValue<T>::SensorValue()
{
    _peek_at_value_queue = xQueueCreate(1, sizeof(T));
    _current_value_queue = xQueueCreate(1, sizeof(T));
}

template <typename T>
SensorValue<T>::~SensorValue()
{
	vQueueDelete(_peek_at_value_queue);
	vQueueDelete(_current_value_queue);	
}
*/